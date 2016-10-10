/*
 * ComMessage.hpp
 */

#ifndef COM_A1_COMMESSAGE_HPP_
#define COM_A1_COMMESSAGE_HPP_

#include <iostream>  // test purposes
#include <vector>

using namespace std;

class ComMsgHeader {

public:
	ComMsgHeader();
	virtual ~ComMsgHeader();

	unsigned char cmd;

};

class ComMsgData {

public:
	ComMsgData();
	virtual ~ComMsgData();

	vector<char>* getData() const;
	void setData(const unsigned char* buff);
	void setData(const vector<char>* buff);

	unsigned int getCRC();
	//todo what about crc


private:
	vector<char> buffer;
	unsigned int crc;
};


class ComMessage {
public:
	ComMessage();
	virtual ~ComMessage();



	static const enum {
		HEADER_LEN = 4,
		DATA_LEN_MAX = 128,
		CRC_LEN = 2
	};

private:
	ComMsgHeader hdr;
	ComMsgData data;
};




#endif /* COM_A1_COMMESSAGE_HPP_ */
