#ifndef BOB_H
#define BOB_H

#include <string>
#include <boost/assign/list_of.hpp>
#include <boost/regex.hpp>

namespace bob
{

// Uppercase letters, with anything you want before or after which is not lowercase letters
static const boost::regex regYelling    = boost::regex("[^a-z]*[A-Z]+[^a-z]*");
static const std::string answerYelling  = "Whoa, chill out!";

// Anything that ends with ? with 0,1 or n spaces at the end
static const boost::regex regQuestion   = boost::regex(".+[?]\\s*");
static const std::string answerQuestion = "Sure.";

// Nothing (like "") or just spaces (0,1 or n like "  ")
static const boost::regex regNoSpeak    = boost::regex("^\\s*$");
static const std::string answerNoSpeak  = "Fine. Be that way!";

// Default behavior, no regex
static const std::string answerOther    = "Whatever.";

// Pair of answer and regex
typedef std::pair<std::string, boost::regex> BobChat;

static std::list<BobChat> bobChat = boost::assign::list_of<BobChat>
                                            (answerYelling, regYelling)
                                            (answerQuestion,regQuestion)
                                            (answerNoSpeak, regNoSpeak);

static std::string hey(const std::string& speach)
{
  for(auto chat : bobChat)
  {
    if(boost::regex_match(speach, chat.second))
      return chat.first;
  }

  return answerOther;
}

}

#endif