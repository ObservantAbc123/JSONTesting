#include "sprite.h"


using std::string;
using std::to_string;

Sprite::Sprite(vector<vector<vector<int>>> framez) {
    string json = "";
    dimensionSquared = 4;
    frames = framez;
}


string Sprite::convertToJson(){
    json += "{\r\n";
    json += "\t\"project\": {";
    json += "\r\n";
    json += "\t\t\"dimension\": ";
    json += dimensionSquared;
    json += "\n";
    json += "\t\t\t\"frames\": [";
    json += "\r\n";
    json = iterateFrames();
    json += "\n}";

    return json;
}

string Sprite::iterateFrames(){
    for(size_t i = 0; i < frames.size(); i++){        
        for(size_t j = 0; j < frames.at(i).size(); j++){       
            json += "\t\t\t";     
            json += "\"frame-pixels\": [";
            json += "\n";
            json += "\t\t\t\t";
            json += "{";
            for(int k = 0; k < dimensionSquared; k++){
                vector<vector<int>> vectorPixels = frames[i];
                vector<int> arrayPixels = vectorPixels[j];                
                json += "\""+ colors[k] + "\""+ ": ";
                json += to_string(arrayPixels[k]);
                if(k < 3){
                    json += ", ";
                }
            }
            if((int)j == dimensionSquared - 1){
                json += "},";
                json += "\r\n";
            }
            else{
                json += "}";
                json += "\r\n";
            }
        }
        json += "\r\n";
        json += "\t\t\t";
        json += "]";
        if(i == frames.size() - 1){
            json += "\t\t";
            json += "},";
        }
        else{
            json += "\t\t";
            json += "}";
        }
        json += "\t\t";
    }
    json += "\t";
    json += "]";

    return json;
}

int main(int argc, char *argv[]){
    vector<vector<vector<int>>> shtuff;
    vector<int> coloration = {200, 30, 50, 255};
    vector<int> coloration2 = {200, 30, 50, 255};
    vector<vector<int>> container;
    container.push_back(coloration);
    container.push_back(coloration2);
    shtuff.push_back(container);

    Sprite sp(shtuff);

    std::cout << sp.convertToJson() << std::endl;
}