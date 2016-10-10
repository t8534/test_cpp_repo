/*
 * str_parse.hpp
 */

/*
 * The text:
 *
 * This is http://www.asa.com.pl and also end of line.<CR><LF>
 * And the line with two ones http://www.basa.com.pl and also http://www.casa.com.pl.<CR><LF>
 * End the end of line http://www.basa.com.pl<CR>.<LF>
 *
 */

#include <iostream>
#include <string>

using namespace std;

void str_parse()
{
	std::size_t begin_pos = 0;
    std::size_t end_pos = 0;
    string text1 = "This is http://www.asa.com.pl and also end of line.\n";
    string text2 = "And the line with two ones http://www.basa.com.pl and also http://www.casa.com.pl.\n";
    string text3 = "End the end of line http://www.basa.com.pl\n";
    string text = text1 + text2 + text3;

    //cout << text << endl;



}
