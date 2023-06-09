#include <iostream>
#include <string>

using namespace std;

class Thousand;
class Hundred;
class Ten;
class Unity;

class Interpreter_roman_nambers{

public:
	Interpreter_roman_nambers();
	explicit Interpreter_roman_nambers(int);
	virtual ~Interpreter_roman_nambers();
	int interprer(string);

	virtual void interprer(string &entry,int &result){
		int index=0;
		string test=entry.substr(0,2);
		
//sprawdznie najwarzniejszych liczb rzymskich
		if(test==nine()){
			wynik+=9*multipliter();
			index+=2;}
		else if(test==four()){
			wynik+=4*multipliter();
			index+=2;}
		else{
			if(entry[0]==five()){
				wynik+=5;
				index=1;}
			else{index=0;}}

//sprawdzaanie jensci ostatnich 3 cyfr,jesli przetem byLa specjalna 5 lub 4
		for (int i = index+3; index<i;index++){
			if(entry[index]==one()){wynik+==1*multipliter();}
			else{break;}}

//wycinanie przerobionej liczby-paru liczb z zakresu 
	int length=entry.length()-index;
	entry=entry.substr(index,length);}

protected:

	virtual char one(){return 0;}
	virtual string four(){return nullptr;}
	virtual char five(){return 0;}
	virtual nine(){return nullptr;}
	virtual multipliter(){return 0;}	

private:

//wskazniki do jendostek aby muc szybko znajdowac funkcje
	Interpreter_roman_nambers *thousand;
	Interpreter_roman_nambers *hundred;
	Interpreter_roman_nambers *ten;
	Interpreter_roman_nambers *unity;

};

class Thousand :public Interpreter_roman_nambers{

public:
	explicit Thousand(int) : Interpreter_roman_nambers(1){};

protected:
	char one() override {return 'M';}
	virtual string four() override {return "";}//brak M jest najwienksze
	virtual char five() override {return '/0';}//sprawdzenie czy koniec lini 
	virtual nine() override {return "";}
	virtual multipliter() override {return 1000;}
	
};

class Hundred :public Interpreter_roman_nambers{

public:
	explicit Hundred(int) : Interpreter_roman_nambers(1){};

protected:
	char one() override {return 'C';}
	virtual string four() override {return "CD";}
	virtual char five() override {return 'D';} 
	virtual nine() override {return "CM";}
	virtual multipliter() override {return 100;}
};

class Ten :public Interpreter_roman_nambers{

public:
	explicit Ten(int) : Interpreter_roman_nambers(1){};

protected:
	char one() override {return 'X';}
	virtual string four() override {return "XL";}
	virtual char five() override {return 'L';} 
	virtual nine() override {return "XC";}
	virtual multipliter() override {return 10;}
};

class Unity :public Interpreter_roman_nambers{

public:
	explicit Unity(int) : Interpreter_roman_nambers(1){};

protected:
	char one() override {return 'I';}
	virtual string four() override {return "IV";}
	virtual char five() override {return 'V';} 
	virtual nine() override {return "IX";}
	virtual multipliter() override {return 1;}
};

Interpreter_roman_nambers::Interpreter_roman_nambers(){
	hundred=new Hundred(1);
	thousand=new Thousand(1);
	ten=new ten(1);
	unity=new Unity(1);}

Interpreter_roman_nambers::interprer(string number){
	if(liczba.empty()){return 0;}
	int total=0;
	thousand->interprer(number,total);
	hundred->interprer(number,total);
	ten->interprer(number,total);
	unity->interprer(number,total);
	return total;}

int main(int argc, char const *argv[])
{
	Interpreter_roman_nambers interprer;
	string number="MMCXLVI"
	cout<<"liczba rzymska  "<<number<<" to liczba dziesietna "<<interprer.interprer(number);
	
	return 0;
}
