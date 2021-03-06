#pragma once
#include "politician.h"
#include "UserCommands.h"
#include "Output.h"

class Conversation
{
	Politician *mp_;
	HistoryLogger<std::string, Idea> *seenIdeas_;
	const Idea legislation_;

	std::string introduction();
	void processCommands();
	std::vector<Idea> createIdeaList();
	std::string createIdeaListString();
	void chooseIdeaToSuggest();
	std::string suggestIdea(const Idea &idea);
	void getCurrentIdeas();
	void endConversation();
	void getHelp();

public:
	Conversation(Politician *mp, HistoryLogger<std::string, Idea> *seenIdeas, const Idea &legislation);
	const static bool politicianAvailable(Politician *mp);
	~Conversation();
};

