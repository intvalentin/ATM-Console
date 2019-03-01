#include <string>
#ifndef LIST_H
#define LIST_H
using namespace std;
class atm{
	
	private:
		struct Nod{
			int ID;
			string nume;
			int pin;
			float credit;
			Nod *next;
		};
		typedef struct Nod *pointer;
		
		pointer primul,temp,log;
		string acc;
		
		public:
			atm(){
				primul=NULL;
			};
			void Afisare(string name);
			void Depunere();
			void Retrager();
			void Logareb();
			void Cont();
			void make();
			int Logarea();
			
				
};

#endif
