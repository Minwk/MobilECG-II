#ifndef ANDROIDAPP_CURVE_H
#define ANDROIDAPP_CURVE_H

#include "DrawableObject.h"
#include <string>
#include <GLES2/gl2.h>
#include "CircularBuffer.h"
#include <vector>
#include "Vec2.h"

class Curve: public DrawableObject{
    public:
        Curve();

        virtual void init(AAssetManager *assetManager);
        virtual void glInit();
        virtual void draw();
        virtual void contextResized(int w, int h);

        static const float POINT_INVALID;

        void setLength(int lengthInPixels);
        void put(float *data, int n);
    private:
        std::string fragmentShader;
        std::string vertexShader;

        Vec2 <GLfloat> screenSize;
        Vec2 <GLfloat> scale;
        Vec2 <GLfloat> position;

        GLfloat color[3];

        static std::vector<GLfloat> invalidBuffer;


        CircularBuffer<GLfloat, 128, true, false> newPointBuffer;

        GLuint shaderProgram;
        GLuint shader_a_Position;
        GLuint shader_screenSize;
        GLuint shader_position;
        GLuint shader_scale;
        GLuint shader_color;
        GLuint shader_a_Value;
        GLuint valueBuffer;

        int requiredNumOfPoints;
        int currNumOfPoints;

        int currWritePos;

        void clear();
        void resizeOnGPU();
        void moveNewDataToGPU();

        static GLuint getXCoordinates();
        static GLfloat *xCoordinates;
        static int xCoordinatesLength;
        static GLuint xCoordinatesOnGPU;
};

#endif //ANDROIDAPP_CURVE_H