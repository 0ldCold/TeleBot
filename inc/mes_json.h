#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/pointer.h"
#include <cstdio>

using namespace std;
using namespace rapidjson;

class mes_json
{
private:
	string chat_id;
public:
	int update_id;
	void set_update_id(int mes_update_id) {
		this->update_id = mes_update_id;
	}
	int get_update_id() {
		return update_id;
	}
	mes_json(string);
	string rapidjson_mes(string, string);
};