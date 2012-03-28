#pragma once

#include <string>

template <typename meta,typename draw_data>
class GBAppState {
public:
	virtual ~GBAppState() 
	{
		delete(drawdata);
        delete(metadata);
	}
	virtual void load_data(std::string filename) = 0;
    meta *metadata;
    draw_data *drawdata;
};
