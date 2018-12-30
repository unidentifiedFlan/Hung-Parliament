#include "NetworkBuilder.h"

NetworkBuilder::NetworkBuilder()
{
	srand(static_cast<unsigned int>(time(0)));
}

Network<Politician*, double>* NetworkBuilder::build(std::unordered_map<std::string, Politician> &MPs, Network<Politician*, double> *network) {

	network_ = network;

	for (std::unordered_map<std::string, Politician>::iterator it = MPs.begin(); it != MPs.end(); ++it) {
		Politician * mp = &(it->second);

		network->addNode(mp);
		buildLinks(mp, MPs);
	}

	return network_;
}

Network<Politician*, double>* NetworkBuilder::buildLinks(Politician *mp, std::unordered_map<std::string, Politician> &MPs) {

	for (std::unordered_map<std::string, Politician>::iterator it2 = MPs.begin(); it2 != MPs.end(); ++it2) {
		Politician * mp2 = &(it2->second);

		if (!(mp == mp2) && !linkExists(mp, mp2) && addProbability(mp, mp2) > randNum()) {
			network_->addLink(mp, mp2, 5);
			network_->addLink(mp2, mp, 5);
		}
	}

	return network_;
}

const bool NetworkBuilder::linkExists(Politician *mp1, Politician *mp2) {
	std::vector<Network<Politician*, double>::Edge> adjNodes = network_->getAdjacentNodes(mp1);

	for (std::vector<Network<Politician*, double>::Edge>::iterator it = adjNodes.begin(); it != adjNodes.end(); ++it) {
		if (it->adjacentNode->get == mp2) {
			return true;
		}
	}

	return false;
}

const double NetworkBuilder::addProbability(Politician *mp1, Politician *mp2) {
	double characsDist = mp1->getCharacteristics().characteristicDistance(mp2->getCharacteristics());

	if (characsDist < 1) {
		return 1;
	}

	int numAdjNodes = network_->getAdjacentNodes(mp1).size();
	if (numAdjNodes == 0) {
		numAdjNodes = 1;
	}

	return 1 / (characsDist*pow(numAdjNodes,2));
}

const double NetworkBuilder::randNum() {
	return (double) rand() / RAND_MAX;
}

NetworkBuilder::~NetworkBuilder()
{
}
