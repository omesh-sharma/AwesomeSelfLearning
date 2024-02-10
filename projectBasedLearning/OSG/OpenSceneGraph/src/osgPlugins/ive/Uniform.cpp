/**********************************************************************
 *
 *    FILE:            Uniform.cpp
 *
 *    DESCRIPTION:    Read/Write osg::Uniform in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerated
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 20.3.2003
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "Uniform.h"
#include "Object.h"
#include <osg/Notify>

using namespace ive;

void Uniform::write(DataOutputStream* out){
    // Write Uniform's identification.
    out->writeInt(IVEUNIFORM);
    // If the osg class is inherited by any other class we should also write this to file.
    osg::Object*  obj = dynamic_cast<osg::Object*>(this);
    if(obj)
    {
        ((ive::Object*)(obj))->write(out);
    }
    else
        out_THROW_EXCEPTION("Uniform::write(): Could not cast this osg::Uniform to an osg::Object.");

    out->writeInt(getType());

    if ( out->getVersion() < VERSION_0012 )
    {
        out->writeString(getName());
    }

    if ( out->getVersion() >= VERSION_0016 )
    {
        out->writeUInt(getNumElements());

        if( getFloatArray() ) out->writeArray( getFloatArray() );
        if( getDoubleArray() ) out->writeArray( getDoubleArray() );
        if( getIntArray() )   out->writeArray( getIntArray() );
        if( getUIntArray() )   out->writeArray( getUIntArray() );
    }
    else
    {
        switch( Uniform::getGlApiType(getType()) )
        {
            case(osg::Uniform::FLOAT):
            {
                float value;
                get(value);
                out->writeFloat(value);
                break;
            }
            case(osg::Uniform::FLOAT_VEC2):
            {
                osg::Vec2 value;
                get(value);
                out->writeVec2(value);
                break;
            }
            case(osg::Uniform::FLOAT_VEC3):
            {
                osg::Vec3 value;
                get(value);
                out->writeVec3(value);
                break;
            }
            case(osg::Uniform::FLOAT_VEC4):
            {
                osg::Vec4 value;
                get(value);
                out->writeVec4(value);
                break;
            }
            case(osg::Uniform::INT):
            {
                int i0;
                get(i0);
                out->writeInt(i0);
                break;
            }
            case(osg::Uniform::INT_VEC2):
            {
                int i0, i1;
                get(i0, i1);
                out->writeInt(i0);
                out->writeInt(i1);
                break;
            }
            case(osg::Uniform::INT_VEC3):
            {
                int i0, i1, i2;
                get(i0, i1, i2);
                out->writeInt(i0);
                out->writeInt(i1);
                out->writeInt(i2);
                break;
            }
            case(osg::Uniform::INT_VEC4):
            {
                int i0, i1, i2, i3;
                get(i0, i1, i2, i3);
                out->writeInt(i0);
                out->writeInt(i1);
                out->writeInt(i2);
                out->writeInt(i3);
                break;
            }
            case(osg::Uniform::FLOAT_MAT2):
            {
                osg::Matrix2 m2;
                get(m2);
                for(int i=0; i<4; ++i) out->writeFloat(m2[i]);
                break;
            }
            case(osg::Uniform::FLOAT_MAT3):
            {
                osg::Matrix3 m3;
                get(m3);
                for(int i=0; i<9; ++i) out->writeFloat(m3[i]);
                break;
            }
            case(osg::Uniform::FLOAT_MAT4):
            {
                osg::Matrixf matrix;
                get(matrix);
                out->writeMatrixf(matrix);
                break;
            }
            default:
            {
                OSG_WARN<<"Warning : uniform "<<getType()<<"type not supported for writing."<<std::endl;
                break;
            }
        }
    }
}

void Uniform::read(DataInputStream* in)
{
    // Read Uniform's identification.
    int id = in->peekInt();
    if(id == IVEUNIFORM)
    {
        // Read Uniform's identification.
        id = in->readInt();
        // If the osg class is inherited by any other class we should also read this from file.
        osg::Object*  obj = dynamic_cast<osg::Object*>(this);
        if(obj)
        {
            ((ive::Object*)(obj))->read(in);
        }
        else
            in_THROW_EXCEPTION("Uniform::read(): Could not cast this osg::Uniform to an osg::Object.");

    }
    else
    {
        in_THROW_EXCEPTION("Uniform::read(): Expected Uniform identification.");
    }

    setType(static_cast<Type>(in->readInt()));

    if ( in->getVersion() < VERSION_0012 )
    {
        setName(in->readString());
    }

    if ( in->getVersion() >= VERSION_0016 )
    {
        setNumElements( in->readUInt() );

        osg::Array* data = in->readArray();
        setArray( dynamic_cast<osg::FloatArray*>(data) );
        setArray( dynamic_cast<osg::DoubleArray*>(data) );
        setArray( dynamic_cast<osg::IntArray*>(data) );
        setArray( dynamic_cast<osg::UIntArray*>(data) );
    }
    else
    {
        switch( Uniform::getGlApiType(getType()) )
        {
            case(osg::Uniform::FLOAT):
            {
                set(in->readFloat());
                break;
            }
            case(osg::Uniform::FLOAT_VEC2):
            {
                set(in->readVec2());
                break;
            }
            case(osg::Uniform::FLOAT_VEC3):
            {
                set(in->readVec3());
                break;
            }
            case(osg::Uniform::FLOAT_VEC4):
            {
                set(in->readVec4());
                break;
            }
            case(osg::Uniform::INT):
            {
                set(in->readInt());
                break;
            }
            case(osg::Uniform::INT_VEC2):
            {
                int i0 = in->readInt();
                int i1 = in->readInt();
                set(i0,i1);
                break;
            }
            case(osg::Uniform::INT_VEC3):
            {
                int i0 = in->readInt();
                int i1 = in->readInt();
                int i2 = in->readInt();
                set(i0,i1,i2);
                break;
            }
            case(osg::Uniform::INT_VEC4):
            {
                int i0 = in->readInt();
                int i1 = in->readInt();
                int i2 = in->readInt();
                int i3 = in->readInt();
                set(i0,i1,i2,i3);
                break;
            }
            case(osg::Uniform::FLOAT_MAT2):
            {
                osg::Matrix2 m2;
                for(int i=0; i<9; ++i) m2[i]=in->readFloat();
                set(m2);
                break;
            }
            case(osg::Uniform::FLOAT_MAT3):
            {
                osg::Matrix3 m3;
                for(int i=0; i<9; ++i) m3[i]=in->readFloat();
                set(m3);
                break;
            }
            case(osg::Uniform::FLOAT_MAT4):
            {
                set( in->readMatrixf() );
                break;
            }
            default:
            {
                OSG_WARN<<"Warning : uniform "<<getType()<<"type not supported for reading."<<std::endl;
                break;
            }
        }
    }
}
