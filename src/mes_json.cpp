#include "../inc/mes_json.h"



mes_json::mes_json(string id)
{
	this->chat_id = id;
	this->update_id = 0;
}

string mes_json::rapidjson_mes(string message, string name) {
	Document document;
	Document result_i;
	string text;
	int update_id = 0;

	document.Parse<0>(message.c_str()).HasParseError();
	if (document.IsObject() == NULL) return "error1";
	if (document.HasMember("ok") == NULL) return "error2";
	document["ok"].IsBool();
	if (document["ok"].GetBool() == NULL) return "error3";
	const Value& result = document["result"];
	if (result.Size() == 0) return "Null";
	result_i.CopyFrom(result[0], result_i.GetAllocator());
	if (result_i.HasMember("update_id") == NULL) return "error4";
	result_i["update_id"].IsInt();
	update_id = result_i["update_id"].GetInt();
	if (!(this->update_id <= update_id + 1)) return "error5";
	this->set_update_id(update_id + 1);
	if (Value* channel_post = GetValueByPointer(result_i, "/channel_post")) {
		if ((*channel_post).HasMember("text") && (*channel_post).HasMember("author_signature"))
		{
			(*channel_post)["author_signature"].IsString();
			if ((*channel_post)["author_signature"].GetString() != name) return "error5";
			(*channel_post)["text"].IsString();
			text = (*channel_post)["text"].GetString();
			return text;
		}
		return "error6";
	}
	return "error7";
}