#pragma once

class Counter
{
    unsigned int count;

public :

    Counter() : count(0) {}

    Counter(int c) : count(c) {}
    
    int get_count() {return count;}


	Counter operator ++ ()
	{
		++count;
		return Counter(count);
	}

	Counter operator --()
	{
		--count;
		return Counter(count);
	}

	Counter operator ++ (int)
	{
		count++;
		return Counter(count);
	}

	Counter operator --(int)
	{
		count--;
		return Counter(count);
	}


};

