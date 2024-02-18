#pragma once

enum GaussGdType
{
	G2 = 2, G3, G4, G5, G6, G7, G8
};


class GaussNodes
{
public:
	GaussNodes(GaussGdType type);

	const double* getGnode() const
	{
		return gnode;
	}

	const double* getGweights() const
	{
		return gweights;
	}

private:

	GaussGdType gt;
	const double* gnode;
	const double* gweights;

};