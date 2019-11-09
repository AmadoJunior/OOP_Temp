#include <iostream>
class Temp{
public:
    int value;
    char type;

    Temp(int value, char type){
        std::cout << "Object created ..." << std::endl;
        this->type = type;
        this->value = value;
    }

    ~Temp(){
        std::cout << "Object destroyed ..." << std::endl;
    }

    void convert(char newType){
        if(newType == this->type){
            return;

        } else if (this->type == 'f'){
            if(newType == 'c'){
                this->type = 'c';
                this->value = (this->value - 32) / 1.8;
            } else if (newType == 'k'){
                this->type = 'k';
                this->value = (this->value - 32) / 1.8 + 273;
            }
        } else if (this->type == 'c'){
            if(newType == 'f'){
                this->type = 'f';
                this->value = (this->value * 1.8) + 32;
            } else if (newType == 'k'){
                this->type = 'k';
                this->value = this->value + 273;
            }
        } else if (this->type == 'k'){
            if(newType == 'c'){
                this->type = 'c';
                this->value = this->value - 273;
            } else if (newType == 'f'){
                this->type = 'f';
                this->value = ((this->value - 273) * 1.8) + 32;
            }
        }
    }

};


int main() {
    Temp roomTemp (40, 'f');
    std::cout << roomTemp.type << std::endl << roomTemp.value << std::endl;
    roomTemp.convert('k');
    std::cout << roomTemp.type << std::endl << roomTemp.value << std::endl;
    return 0;
}