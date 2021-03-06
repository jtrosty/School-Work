#include <iostream>
#include <fstream>
#include <string.h>

#include "ImageProcessing.h"

using std::ifstream;
using std::ios_base;
using std::string;
using std::cout;
using std::endl;
using std::cin;

#include "leaker.h"
int main() { //string fileToCopy = "..\\input\\layer1.tga";
    ImageProcessingTGA imageProcessor;
    /*
    imageProcessor.readInFileTGA("src\\test.tga");
    cout << "the header #############################  THIs work" << endl;
    ImageProcessingTGA::HeaderTGA y = *imageProcessor.getPicture(0).header;
    imageProcessor.writeFileTGA(imageProcessor.getPicture(0));
    cout << "Commence test" << endl;
    imageProcessor.testPictures("writeTest.tga", "src\\test.tga"); 

    char a = (char)72;
    char b = (char)72;
    char c = (char)20;
    char d = (char)((((float)a / 255) * ((float)b / 255)) * 255);
    cout << "a " << a << " b " << b << " c " << c << " result " << d << endl;
    */

   /*
   0. layer1.tga
   1. patter1.tga
   2. part1.tga
   3. layer2.tga
   4. car.tga
   5. part2.tga
   6. pattern2.tga
   7. text.tga
   8. part3 int multiply
   9. part3.tga
   10. circle.tga
   11. part 4 int, multiply of 3 and 10
   12. part4.tga
   13. part5.tga
   14. part6.tga
   15. part7.tga
   16. part8_r.tga
   17. part8_g.tga
   18. part8_b.tga
   19. layer_red.tga
   20. layer_green.tga
   21. layer_blue.tga
   22. part9.tga
   23. text2.tga
   24. part10.tga
   25. extracredit.tga
   */

    // PART 1 ##############################################
    cout << "Part 1 Multiply ################################################" << endl;
    imageProcessor.readInFileTGA("input\\Layer1.tga");
    imageProcessor.readInFileTGA("input\\pattern1.tga");
    imageProcessor.multiply(imageProcessor.getPicture(0), imageProcessor.getPicture(1));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(2), "output\\part1.tga");
    imageProcessor.testPictures("output\\part1.tga", "examples\\EXAMPLE_part1.tga");
    
    // PART 2 #############################################
    cout << "Begin Part 2 ####################################################" << endl;
    imageProcessor.readInFileTGA("input\\Layer2.tga");
    imageProcessor.readInFileTGA("input\\car.tga");
    imageProcessor.subtract(imageProcessor.getPicture(4), imageProcessor.getPicture(3));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(5), "output\\part2.tga");
    imageProcessor.testPictures("output\\part2.tga", "examples\\EXAMPLE_part2.tga");

    // PART 3 #############################################
    cout << "Begin Part 3 ####################################################" << endl;
    imageProcessor.readInFileTGA("input\\pattern2.tga");
    imageProcessor.readInFileTGA("input\\text.tga");
    imageProcessor.multiply(imageProcessor.getPicture(0), imageProcessor.getPicture(6));
    imageProcessor.screen(imageProcessor.getPicture(8), imageProcessor.getPicture(7));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(9), "output\\part3.tga");
    imageProcessor.testPictures("output\\part3.tga", "examples\\EXAMPLE_part3.tga");

    // PART 4 #############################################
    cout << "Begin Part 4 ####################################################" << endl;
    imageProcessor.readInFileTGA("input\\circles.tga");
    imageProcessor.multiply(imageProcessor.getPicture(3), imageProcessor.getPicture(10));
    imageProcessor.subtract(imageProcessor.getPicture(11), imageProcessor.getPicture(6));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(12), "output\\part4.tga");
    imageProcessor.testPictures("output\\part4.tga", "examples\\EXAMPLE_part4.tga");

    // PART 5 #############################################
    cout << "Begin Part 5 ####################################################" << endl;
    imageProcessor.overlay(imageProcessor.getPicture(0), imageProcessor.getPicture(1));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(13), "output\\part5.tga");
    imageProcessor.testPictures("output\\part5.tga", "examples\\EXAMPLE_part5.tga");

    // PART 6 #############################################
    cout << "Begin Part 6 ####################################################" << endl;
    imageProcessor.addAdjustRGB(imageProcessor.getPicture(4), 0, 200, 0);
    imageProcessor.writeFileTGA(imageProcessor.getPicture(14), "output\\part6.tga");
    imageProcessor.testPictures("output\\part6.tga", "examples\\EXAMPLE_part6.tga");

    // PART 7 #############################################
    cout << "Begin Part 7 ####################################################" << endl;
    imageProcessor.scaleAdjustRGB(imageProcessor.getPicture(4), 4.0f, 1.0f, 0.0f);
    imageProcessor.writeFileTGA(imageProcessor.getPicture(15), "output\\part7.tga");
    imageProcessor.testPictures("output\\part7.tga", "examples\\EXAMPLE_part7.tga");

    // PART 8 #############################################
    cout << "Begin Part 8 ####################################################" << endl;
    imageProcessor.individualChannel(imageProcessor.getPicture(4), 'r');
    imageProcessor.individualChannel(imageProcessor.getPicture(4), 'g');
    imageProcessor.individualChannel(imageProcessor.getPicture(4), 'b');
    imageProcessor.writeFileTGA(imageProcessor.getPicture(16), "output\\part8_r.tga");
    imageProcessor.writeFileTGA(imageProcessor.getPicture(17), "output\\part8_g.tga");
    imageProcessor.writeFileTGA(imageProcessor.getPicture(18), "output\\part8_b.tga");
    imageProcessor.testPictures("output\\part8_r.tga", "examples\\EXAMPLE_part8_r.tga");
    imageProcessor.testPictures("output\\part8_g.tga", "examples\\EXAMPLE_part8_g.tga");
    imageProcessor.testPictures("output\\part8_b.tga", "examples\\EXAMPLE_part8_b.tga");

    // PART 9 #############################################
    cout << "Begin Part 9 ####################################################" << endl;
    imageProcessor.readInFileTGA("input\\Layer_red.tga");
    imageProcessor.readInFileTGA("input\\Layer_green.tga");
    imageProcessor.readInFileTGA("input\\Layer_blue.tga");
    imageProcessor.combinePicsEachOneChannel(imageProcessor.getPicture(19), imageProcessor.getPicture(20), imageProcessor.getPicture(21));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(22), "output\\part9.tga");
    imageProcessor.testPictures("output\\part9.tga", "examples\\EXAMPLE_part9.tga");

    // PART 10 #############################################
    cout << "Begin Part 10 ####################################################" << endl;
    imageProcessor.readInFileTGA("input\\text2.tga");
    imageProcessor.rotate180(imageProcessor.getPicture(23));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(24), "output\\part10.tga");
    imageProcessor.testPictures("output\\part10.tga", "examples\\EXAMPLE_part10.tga");

    // PART EXTRA CREDIT #############################################
    cout << "Begin Extra Credit ####################################################" << endl;
    imageProcessor.extraCreditCombine4Pics(imageProcessor.getPicture(4), imageProcessor.getPicture(10), imageProcessor.getPicture(7), imageProcessor.getPicture(1));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(25), "output\\extracredit.tga");
    imageProcessor.testPictures("output\\extracredit.tga", "examples\\EXAMPLE_extracredit.tga");
    return 0;
    char layer1[] = "input\\Layer1.tga";

/*
    char pattern1[] = "input\\patern1.tga";
    char pattern2[] = "input\\patern2.tga";
    char layer2[] = "input\\Layer2.tga";
    char car[] = "input\\car.tga";
    char text[] = "input\\text.tga";
    char circles[] = "input\\circles.tga";
    char layerRed[] = "input\\layer_red.tga";
    char layerGreen[] = "input\\layer_green.tga";
    char layerBlue[] = "input\\layer_blue.tga";
    char text2[] = "input\\text2.tga";

    char outPart1[] = "output\\part1.tga";
    char outPart2[] = "output\\part2.tga";
    char outPart3[] = "output\\part3.tga";
    char outPart4[] = "output\\part4.tga";
    char outPart5[] = "output\\part5.tga";
    char outPart6[] = "output\\part6.tga";
    char outPart7[] = "output\\part7.tga";
    char outPart8Red[] = "output\\part8_r.tga";
    char outPart8Green[] = "output\\part8_g.tga";
    char outPart8Blue[] = "output\\part8_b.tga";
    char outPart9[] = "output\\part9.tga";
    char outPart10[] = "output\\part10.tga";
    char outExtraCredit[] = "output\\extracredit.tga";

    char exPart1[] = "examples\\EXAMPLE_part1.tga";
    char exPart2[] = "examples\\EXAMPLE_part2.tga";
    char exPart3[] = "examples\\EXAMPLE_part3.tga";
    char exPart4[] = "examples\\EXAMPLE_part4.tga";
    char exPart5[] = "examples\\EXAMPLE_part5.tga";
    char exPart6[] = "examples\\EXAMPLE_part6.tga";
    char exPart7[] = "examples\\EXAMPLE_part7.tga";
    char exPart8_r[] = "examples\\EXAMPLE_part8_r.tga";
    char exPart8_g[] = "examples\\EXAMPLE_part8_g.tga";
    char exPart8_b[] = "examples\\EXAMPLE_part8_b.tga";
    char exPart9[] = "examples\\EXAMPLE_part9.tga";
    char exPart10[] = "examples\\EXAMPLE_part10.tga";
    char exExtraCredit[] = "examples\\EXAMPLE_extracredit.tga";

    // PART 1 ##############################################
    cout << "Part 1 Multiply ################################################" << endl;
    imageProcessor.readInFileTGA(layer1);
    imageProcessor.readInFileTGA(pattern1);
    imageProcessor.multiply(imageProcessor.getPicture(0), imageProcessor.getPicture(1));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(2), outPart1);
    imageProcessor.testPictures(outPart1, exPart1);
    
    // PART 2 #############################################
    cout << "Begin Part 2 ####################################################" << endl;
    imageProcessor.readInFileTGA(layer2);
    imageProcessor.readInFileTGA(car);
    imageProcessor.subtract(imageProcessor.getPicture(4), imageProcessor.getPicture(3));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(5), outPart2);
    imageProcessor.testPictures(outPart2, exPart2);

    // PART 3 #############################################
    cout << "Begin Part 3 ####################################################" << endl;
    imageProcessor.readInFileTGA(pattern2);
    imageProcessor.readInFileTGA(text);
    imageProcessor.multiply(imageProcessor.getPicture(0), imageProcessor.getPicture(6));
    imageProcessor.screen(imageProcessor.getPicture(8), imageProcessor.getPicture(7));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(9), outPart3);
    imageProcessor.testPictures(outPart3, exPart3);

    // PART 4 #############################################
    cout << "Begin Part 4 ####################################################" << endl;
    imageProcessor.readInFileTGA(circles);
    imageProcessor.multiply(imageProcessor.getPicture(3), imageProcessor.getPicture(10));
    imageProcessor.subtract(imageProcessor.getPicture(11), imageProcessor.getPicture(6));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(12), outPart4);
    imageProcessor.testPictures(outPart4, exPart4);

    // PART 5 #############################################
    cout << "Begin Part 5 ####################################################" << endl;
    imageProcessor.overlay(imageProcessor.getPicture(0), imageProcessor.getPicture(1));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(13), outPart5);
    imageProcessor.testPictures(outPart5, exPart5);

    // PART 6 #############################################
    cout << "Begin Part 6 ####################################################" << endl;
    imageProcessor.addAdjustRGB(imageProcessor.getPicture(4), 0, 200, 0);
    imageProcessor.writeFileTGA(imageProcessor.getPicture(14), outPart6);
    imageProcessor.testPictures(outPart6, exPart6);

    // PART 7 #############################################
    cout << "Begin Part 7 ####################################################" << endl;
    imageProcessor.scaleAdjustRGB(imageProcessor.getPicture(4), 4.0f, 1.0f, 0.0f);
    imageProcessor.writeFileTGA(imageProcessor.getPicture(15), outPart7);
    imageProcessor.testPictures(outPart7, exPart7);

    // PART 8 #############################################
    cout << "Begin Part 8 ####################################################" << endl;
    imageProcessor.individualChannel(imageProcessor.getPicture(4), 'r');
    imageProcessor.individualChannel(imageProcessor.getPicture(4), 'g');
    imageProcessor.individualChannel(imageProcessor.getPicture(4), 'b');
    imageProcessor.writeFileTGA(imageProcessor.getPicture(16), outPart8Red);
    imageProcessor.writeFileTGA(imageProcessor.getPicture(17), outPart8Green);
    imageProcessor.writeFileTGA(imageProcessor.getPicture(18), outPart8Blue);
    imageProcessor.testPictures(outPart8Red, exPart8_r);
    imageProcessor.testPictures(outPart8Green, exPart8_g);
    imageProcessor.testPictures(outPart8Blue, exPart8_b);

    // PART 9 #############################################
    cout << "Begin Part 9 ####################################################" << endl;
    imageProcessor.readInFileTGA(layerRed);
    imageProcessor.readInFileTGA(layerGreen);
    imageProcessor.readInFileTGA(layerBlue);
    imageProcessor.combinePicsEachOneChannel(imageProcessor.getPicture(19), imageProcessor.getPicture(20), imageProcessor.getPicture(21));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(22), outPart9);
    imageProcessor.testPictures(outPart9, exPart9);

    // PART 10 #############################################
    cout << "Begin Part 10 ####################################################" << endl;
    imageProcessor.readInFileTGA(text2);
    imageProcessor.rotate180(imageProcessor.getPicture(23));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(24), outPart10);
    imageProcessor.testPictures(outPart10, exPart10);

    // PART EXTRA CREDIT #############################################
    cout << "Begin Extra Credit ####################################################" << endl;
    imageProcessor.extraCreditCombine4Pics(imageProcessor.getPicture(4), imageProcessor.getPicture(10), imageProcessor.getPicture(7), imageProcessor.getPicture(1));
    imageProcessor.writeFileTGA(imageProcessor.getPicture(25), outExtraCredit);
    imageProcessor.testPictures(outExtraCredit, exExtraCredit);
*/
}