enum States
{
    A, B, C
};

%%
((test\\?)|(1?)*)+[a-zV0-9]	  return A;
a|(b[^a-b][ \t\n])*	              return B;