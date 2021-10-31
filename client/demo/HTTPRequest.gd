extends HTTPRequest


func _ready():
	connect("request_completed", self, "_on_request_completed")
	request("http://127.0.0.1:3000")


func _on_request_completed(result, response_code, headers, body):
	var json = JSON.parse(body.get_string_from_utf8())
	print(json.result)
