import os
import requests
from bs4 import BeautifulSoup
import re

def download_html(client_id, _uid, url='https://www.luogu.com.cn/feed/watching?page=1', filename='document.html'):
    """
    下载 HTML 内容并保存为文件
    :param client_id: 用户的 client_id，用于作为 Cookie
    :param _uid: 用户的 _uid，用于作为 Cookie
    :param url: 要下载 HTML 内容的 URL
    :param filename: 保存 HTML 内容的文件名
    """
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    }

    cookies = {
        '__client_id': client_id,
        '_uid': _uid
    }

    try:
        # 发送 GET 请求并附加 Cookies
        response = requests.get(url, headers=headers, cookies=cookies)
        response.raise_for_status()  # 如果请求失败，将抛出异常
        
        # 将下载的 HTML 内容保存到文件
        with open(filename, 'w', encoding='utf-8') as file:
            file.write(response.text)
        print(f"HTML 文件已成功下载并保存为 {filename}")
    except requests.RequestException as e:
        print(f"下载 HTML 文件时发生错误: {e}")

# 从环境变量获取 client_id 和 _uid
client_id = os.getenv('luogu_cookie')  # 从环境变量获取 client_id
_uid = os.getenv('luogu_uid')  # 从环境变量获取 _uid

if client_id and _uid:
    # 下载 HTML 文件
    download_html(client_id, _uid)

    # 用于存储提取的信息
    extracted_info = []

    # 打开并读取 HTML 文件
    try:
        with open('document.html', 'r', encoding='utf-8') as file:
            content = file.read()
            
            # 使用 BeautifulSoup 解析 HTML 内容
            soup = BeautifulSoup(content, 'html.parser')
            
            # 提取所有用户名（opzc35）
            usernames = soup.find_all('a', class_='lg-fg-orange lg-bold')
            for username in usernames:
                extracted_info.append(f"Username: {username.text.strip()}")

            # 提取所有用户 ID（737496）
            user_ids = soup.find_all('a', href=re.compile(r"https://www\.luogu\.com\.cn/user/\d+"))
            for user_id in user_ids:
                match = re.search(r"(\d+)$", user_id['href'])
                if match:
                    extracted_info.append(f"User ID: {match.group(1)}")
            
            # 提取所有消息
            comments = soup.find_all('span', class_='feed-comment')
            for comment in comments:
                message = comment.get_text().strip()
                if message:
                    extracted_info.append(f"Message: {message}")

        # 打印提取的信息
        if extracted_info:
            print("提取到的信息:")
            for info in extracted_info:
                print(info)
        else:
            print("未提取到任何信息。")

    except FileNotFoundError:
        print("文件 document.html 未找到，请确保文件存在并提供正确路径。")
    except Exception as e:
        print(f"读取文件时发生错误: {e}")
else:
    print("未找到客户端 ID 或用户 ID。请确保已设置环境变量 CLIENT_ID 和 UID。")
