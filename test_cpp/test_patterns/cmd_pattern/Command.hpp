/*
 * Command.hpp
 *
 *  Created on: Jun 30, 2016
 *      Author: liberdaa
 */

#ifndef CMD_PATTERN_COMMAND_HPP_
#define CMD_PATTERN_COMMAND_HPP_

class Command {
public:
	virtual void execute() = 0;
	Command();
	virtual ~Command();
};

#endif /* CMD_PATTERN_COMMAND_HPP_ */
