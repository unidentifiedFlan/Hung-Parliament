#pragma once
#include "politician.h"
#include "UserCommands.h"
#include "Output.h"

class Conversation
{
	Politician *mp_;
	HistoryLogger<std::string, const Idea*> *seenIdeas_;
	const Idea legislation_;

	std::string introduction();
	void processCommands();
	void suggestIdea();
	void getCurrentIdeas();
	void endConversation();
	void getHelp();

public:
	Conversation(Politician *mp, HistoryLogger<std::string, const Idea*> *seenIdeas, const Idea legislation);
	const static bool politicianAvailable(Politician *mp);
	~Conversation();
};

