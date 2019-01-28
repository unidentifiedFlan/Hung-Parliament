#pragma once
#include "stdafx.h"
#include <stack>
#include "Listener.h"
#include "Politician.h"
#include "DynamicNetwork.h"
#include "PoliticianLists.h"

class Parliament : public Listener, public Publisher
{
	static const unsigned int NUM_POLITICIANS_PER_IDEA = 5;

	std::vector<std::string> characteristicNames_ = { "egalitarian", "econLib", "authoritarian" };
	
	int numMPs_ = 0;
	std::unordered_map<std::string, Politician> MPs_;
	std::unordered_map<std::string, Politician>::iterator nextMP_ = MPs_.begin();
	std::unordered_map<std::string, Politician>::iterator lastMP_ = MPs_.end();

	std::stack<Idea> legislation_;
	Ideas ideas_;
	Ideas::Iterator nextIdea_;
	Ideas::Iterator lastIdea_;

	DynamicNetwork *network_;

	const Idea getNextIdea();
	Ideas buildIdeas(const unsigned int &numMPs);
	std::unordered_map<std::string, Politician> buildMPs(const unsigned int &numMPs);

public:
	Parliament(const unsigned int &numMPs, DynamicNetwork *network);
	Ideas spawnNewIdeas(const unsigned int &numIdeas);

	void handleEvent(Event &e);

	Politician* findMP(std::string mp);
	std::vector<Network<Politician*, double>::Edge> getMPConnections(Politician* mp) const;
    Politician* getNextMP();
	int getNumberOfMPs();
	PoliticianLists createPoliticianLists();

	Idea getLegislation();

	bool calculateMPSupport(Politician *mp) const;

	~Parliament();
};

