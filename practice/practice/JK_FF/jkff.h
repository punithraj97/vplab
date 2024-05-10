#include<systemc.h>
SC_MODULE(jkfff)
{
	
	
	sc_in<bool> j,k,rst;
	sc_out<bool> q,qb;
	sc_in<bool> clk;
	
	void function()
	{
	
	
		if(rst.read())
		{
			q.write(0);
			qb.write(1);	
		}
		else
		{
		if(!(j.read()) && !(k.read()))
		{
			q.write(q);
			qb.write(qb);		
		}
		else if(j.read()==0 && k.read()==1)
		{
			q.write(false);
			qb.write(true);
		}
		else if(j.read()==1 && k.read()==0)
		{
			q.write(true);
			qb.write(false);
		}
		else if(j.read()==1 && k.read()==1)
		{
			q.write(!q);
			qb.write(!qb);
		}
		}
	}
	
	
	SC_CTOR(jkfff)
	{
		SC_METHOD(function);
		sensitive<<clk.pos();
		
	}
	
	
	
	
};
