#include"importer.h"
#include"alloccater.h"
int main(){
    
    importer loater;
    loater.getnumarray("../prog1_resource/5000.in"); // 0.65sec at 5000
    cout<<"==================";//<<endl;
    loater.resultable();    
    return 0;
}

//sample output::
// ======================
//         Parser        
// ======================
// #Chords:12
// Chord(0,4)
// Chord(1,9)
// Chord(2,6)
// Chord(3,10)
// Chord(5,7)
// Chord(8,11)
