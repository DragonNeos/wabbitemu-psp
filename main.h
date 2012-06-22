
// Structures
struct CALCBUNDLE {
	LPCALC lpCalc;
	OSL_IMAGE *currentscreen;
};

//functions
int main();
struct CALCBUNDLE CreateCalc(BOOL StartCalculator, LPCTSTR RomName);
void TimerFunc(struct CALCBUNDLE MyCalc); //function that handle the update of calculators, update the screen etc: it's called x times/sec according to the framerate
void UpdateDisplay(struct CALCBUNDLE MyCalc); //function called by TimerFunc: it refreshes the screen according to the current state of the virtual calculator
void KeysHandler(struct CALCBUNDLE *MyCalc); //change
void CreatePalette();
