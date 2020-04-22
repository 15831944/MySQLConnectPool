#include <iostream>

#include "MysqlConnectPool.h"

std::string db_name = "LiveUser";
std::string db_ip = "thatboy.info";
std::string db_user = "thatboy";
std::string db_passwd = "Thatboy_512906409";
int db_port = 3306;
std::string db_charset = "utf8";

int main()
{
	//db_pool = std::make_shared<MysqlConnectPool>(db_name, db_ip, db_user, db_passwd, db_port, db_charset);
	thatboy::sql::ConnectPool db_pool(db_name, db_ip, db_user, db_passwd, db_port, db_charset);

	try {
		mysqlpp::ScopedConnection conn(db_pool);
		mysqlpp::Query query = conn->query("select * from LiveUser.live_user");

		auto ret = query.store();

		for (auto it : ret)
		{
			for (auto it : it)
			{
				std::cout << it << std::endl;
			}
			std::cout << std::endl;
		}

		//................................
	}
	catch (const mysqlpp::Exception& e) {
		std::cout << "error:" << e.what() << "\n";
		return false;
	}
	Sleep(2000);
	return 0;
}