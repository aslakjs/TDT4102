#include "masterVisual.h"
void addGuess(MastermindWindow& mwin,const string code,const int size, const char startLetter, const int round, string guess){
	char currGuess;
    int c, xPos, yPos;

    for (int i = 0; i < size; i++) {
        if (round == -1) {  // Final code when done
            currGuess = guess[i];
            c = getColor(currGuess);
            
            xPos = padX + (i*padX*2);
            yPos = 3*padY;

            mwin.vr.push_back(new Rectangle{Point{xPos,yPos},padX, padY});
            mwin.vr[mwin.vr.size()-1].set_fill_color(c);
            mwin.attach(mwin.vr[mwin.vr.size()-1]);
        }
        else {      // Current guess squares
            currGuess = guess[i];
            c = getColor(currGuess);
            
            xPos = padX + (i*padX*2);
            yPos = 3*padY + (round*padY*2);

            mwin.vr.push_back(new Rectangle{Point{xPos,yPos},padX, padY});
            mwin.vr[mwin.vr.size()-1].set_fill_color(c);
            mwin.attach(mwin.vr[mwin.vr.size()-1]);
        }
    }
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter, const int size, const int round){
    int xPos, yPos;

    for (int i = 0; i < size; i++) { // Empty circles
        xPos = 8.5*padX + (i*padX*0.2);
        yPos = 3.5*padY + (round*padY*2);
        mwin.vc.push_back(new Circle{Point{xPos,yPos},radCircle});
        if ((i+1) <= correctPosition) {
            mwin.vc[mwin.vc.size()-1].set_fill_color(0);
        }
        else if ((( (i+1) > correctPosition ) && ( (i+1) <= correctCharacter )) || ((correctPosition == 0) && ((i+1) <= correctCharacter))) {
            mwin.vc[mwin.vc.size()-1].set_fill_color(10);
        }
        else {
            mwin.vc[mwin.vc.size()-1].set_color(0);
        }
        mwin.attach(mwin.vc[mwin.vc.size()-1]);
    }
}

void hideCode(MastermindWindow &mwin,const int size){
	mwin.vr.push_back(new Rectangle{Point{padX,3*padY},winW-size*padX,padY});
	mwin.vr[mwin.vr.size()-1].set_fill_color(Color::black);
	mwin.attach(mwin.vr[mwin.vr.size()-1]);
}

MastermindWindow::MastermindWindow(Point xy,int w, int h, const string& title):Window(xy,w,h,title),
    button_pressed{false},
	guessBtn{upperLeftCornerBtn,btnW,btnH,"Add",cb_guess},
    guess{upperLeftCornerInBox,inBoxW,inBoxH,"Guess"},
    code{{padX,padY+(2*padY)},0,29,"Code:"},
    r1{{padX,padY+(4*padY)},0,29,"R1:"},
    r2{{padX,padY+(6*padY)},0,29,"R2:"},
    r3{{padX,padY+(8*padY)},0,29,"R3:"},
    r4{{padX,padY+(10*padY)},0,29,"R4:"},
    r5{{padX,padY+(12*padY)},0,29,"R5:"},
    r6{{padX,padY+(14*padY)},0,29,"R6:"},
    r7{{padX,padY+(16*padY)},0,29,"R7:"},
    r8{{padX,padY+(18*padY)},0,29,"R8:"},
    r9{{padX,padY+(20*padY)},0,29,"R9:"},
    r10{{padX,padY+(22*padY)},0,29,"R10:"}
    {
        attach(guess);
        attach(guessBtn);
        attach(code);
        attach(r1);
        attach(r2);
        attach(r3);
        attach(r4);
        attach(r5);
        attach(r6);
        attach(r7);
        attach(r8);
        attach(r9);
        attach(r10);
};

 string MastermindWindow::wait_for_guess(){
		while (!button_pressed)
			Fl::wait();
		button_pressed = false;
		Fl::redraw();
        string newGuess =guess.get_string();
        guess.clear_value();
        return newGuess;
}


string MastermindWindow::getInput(unsigned int n, char lower, char upper){
	bool validInput = false;
	string guess;
	while(!validInput){
		guess.clear();
		string input = wait_for_guess();
		if(input.size() == n){
			for(unsigned int i = 0; i < n; i++){
				char ch = input[i];
				if(isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch)){
					guess += toupper(ch);
				} 
				else 
				break;
			}
		}
		if(guess.size() == n) validInput=true;
		else cout<<"Invalid input guess again\n";
	}
	return guess;
}


int getColor(char guess) {
    int color = 0;
    if (guess == 'A') {color = 1;}
    else if (guess == 'B') {color = 2;}
    else if (guess == 'C') {color = 3;}
    else if (guess == 'D') {color = 4;}
    else if (guess == 'E') {color = 5;}
    else if (guess == 'F') {color = 6;}
    return color;
}

void hideSecret(MastermindWindow& mwin, const int size) {
    int xPos, yPos;
    for (int i = 0; i < size; i++) {
        xPos = padX + (i*padX*2);
        yPos = 3*padY;

        mwin.vr.push_back(new Rectangle{Point{xPos,yPos},padX, padY});
        mwin.vr[mwin.vr.size()-1].set_fill_color(0);
        mwin.attach(mwin.vr[mwin.vr.size()-1]);
    }
}