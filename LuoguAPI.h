#include<bits/stdc++.h>
using namespace std;

void focuson(int uid,string client_id,string _uid) {
	string command = "curl \"https://www.luogu.com/api/user/updateRelationShip\" "
	"-H \"accept: application/json, text/plain, */*\" "
	"-H \"accept-language: zh-CN,zh;q=0.9\" "
	"-H \"content-type: application/json\" "
	"-H \"cookie: __client_id="+client_id+"; _uid="+_uid+"; C3VK=7e6492\" "
	"-H \"dnt: 1\" "
	"-H \"origin: https://www.luogu.com.cn\" "
	"-H \"priority: u=1, i\" "
	"-H \"referer: https://www.luogu.com/user/"+to_string(uid)+"\" "
	"-H \"sec-ch-ua: \\\"Microsoft Edge\\\";v=\\\"131\\\", \\\"Chromium\\\";v=\\\"131\\\", \\\"Not_A Brand\\\";v=\\\"24\\\"\" "
	"-H \"sec-ch-ua-mobile: ?0\" "
	"-H \"sec-ch-ua-platform: \\\"Windows\\\"\" "
	"-H \"sec-fetch-dest: empty\" "
	"-H \"sec-fetch-mode: cors\" "
	"-H \"sec-fetch-site: same-origin\" "
	"-H \"user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0\" "
	"-H \"x-csrf-token: 1733568348:Z+/AOI9v83jwmU+/0Fjzc54HFDS16GkfpgkkCVLExqw=\" "
	"-H \"x-requested-with: XMLHttpRequest\" "
	"--data-raw \"{\\\"uid\\\":"+to_string(uid)+",\\\"relationship\\\":1}\"";
	system(command.c_str());
}
void unfocuson(int uid,string client_id,string _uid) {
	string command = "curl \"https://www.luogu.com/api/user/updateRelationShip\" "
	"-H \"accept: application/json, text/plain, */*\" "
	"-H \"accept-language: zh-CN,zh;q=0.9\" "
	"-H \"content-type: application/json\" "
	"-H \"cookie: __client_id="+client_id+"; _uid="+_uid+"; C3VK=7e6492\" "
	"-H \"dnt: 1\" "
	"-H \"origin: https://www.luogu.com\" "
	"-H \"priority: u=1, i\" "
	"-H \"referer: https://www.luogu.com/user/"+to_string(uid)+"\" "
	"-H \"sec-ch-ua: \\\"Microsoft Edge\\\";v=\\\"131\\\", \\\"Chromium\\\";v=\\\"131\\\", \\\"Not_A Brand\\\";v=\\\"24\\\"\" "
	"-H \"sec-ch-ua-mobile: ?0\" "
	"-H \"sec-ch-ua-platform: \\\"Windows\\\"\" "
	"-H \"sec-fetch-dest: empty\" "
	"-H \"sec-fetch-mode: cors\" "
	"-H \"sec-fetch-site: same-origin\" "
	"-H \"user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0\" "
	"-H \"x-csrf-token: 1733568348:Z+/AOI9v83jwmU+/0Fjzc54HFDS16GkfpgkkCVLExqw=\" "
	"-H \"x-requested-with: XMLHttpRequest\" "
	"--data-raw \"{\\\"uid\\\":"+to_string(uid)+",\\\"relationship\\\":0}\"";
	system(command.c_str());
}
