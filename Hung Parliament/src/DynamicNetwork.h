#pragma once
#include "stdafx.h"
#include "Network.h"
#include "Politician.h"
#include "MPIsingModel.h"

class DynamicNetwork : public Network<Politician*, double>
{
	time_t runInterval_;
	time_t lastRunTime_;
	MPIsingModel model_;

	void getIdeasFromAdjacentMPs(Politician* randMP, const std::vector<Edge> adjNodes);
	void compareAdjacentIdeas(Politician* currentMP, Edge linkedMP);

public:
	DynamicNetwork(int interval, const MPIsingModel &model);
	void runDynamics(bool *quit);

	Politician* getRandomNode();

	~DynamicNetwork() {}
};