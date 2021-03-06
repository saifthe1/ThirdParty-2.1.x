/*****************************************************************************
*
* Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400124
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

#include <SimilarityTransformAttributes.h>
#include <DataNode.h>
#include <BoxExtents.h>

//
// Enum conversion methods for SimilarityTransformAttributes::AngleType
//

static const char *AngleType_strings[] = {
"Deg", "Rad"};

std::string
SimilarityTransformAttributes::AngleType_ToString(SimilarityTransformAttributes::AngleType t)
{
    int index = int(t);
    if(index < 0 || index >= 2) index = 0;
    return AngleType_strings[index];
}

std::string
SimilarityTransformAttributes::AngleType_ToString(int t)
{
    int index = (t < 0 || t >= 2) ? 0 : t;
    return AngleType_strings[index];
}

bool
SimilarityTransformAttributes::AngleType_FromString(const std::string &s, SimilarityTransformAttributes::AngleType &val)
{
    val = SimilarityTransformAttributes::Deg;
    for(int i = 0; i < 2; ++i)
    {
        if(s == AngleType_strings[i])
        {
            val = (AngleType)i;
            return true;
        }
    }
    return false;
}

// Type map format string
const char *SimilarityTransformAttributes::TypeMapFormatString = "bFFfibFfffbfff";

// ****************************************************************************
// Method: SimilarityTransformAttributes::SimilarityTransformAttributes
//
// Purpose: 
//   Constructor for the SimilarityTransformAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SimilarityTransformAttributes::SimilarityTransformAttributes() : 
    AttributeSubject(SimilarityTransformAttributes::TypeMapFormatString)
{
    doRotate = false;
    rotateOrigin[0] = 0;
    rotateOrigin[1] = 0;
    rotateOrigin[2] = 0;
    rotateAxis[0] = 0;
    rotateAxis[1] = 0;
    rotateAxis[2] = 1;
    rotateAmount = 0;
    rotateType = Deg;
    doScale = false;
    scaleOrigin[0] = 0;
    scaleOrigin[1] = 0;
    scaleOrigin[2] = 0;
    scaleX = 1;
    scaleY = 1;
    scaleZ = 1;
    doTranslate = false;
    translateX = 0;
    translateY = 0;
    translateZ = 0;
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::SimilarityTransformAttributes
//
// Purpose: 
//   Copy constructor for the SimilarityTransformAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SimilarityTransformAttributes::SimilarityTransformAttributes(const SimilarityTransformAttributes &obj) : 
    AttributeSubject(SimilarityTransformAttributes::TypeMapFormatString)
{
    doRotate = obj.doRotate;
    rotateOrigin[0] = obj.rotateOrigin[0];
    rotateOrigin[1] = obj.rotateOrigin[1];
    rotateOrigin[2] = obj.rotateOrigin[2];

    rotateAxis[0] = obj.rotateAxis[0];
    rotateAxis[1] = obj.rotateAxis[1];
    rotateAxis[2] = obj.rotateAxis[2];

    rotateAmount = obj.rotateAmount;
    rotateType = obj.rotateType;
    doScale = obj.doScale;
    scaleOrigin[0] = obj.scaleOrigin[0];
    scaleOrigin[1] = obj.scaleOrigin[1];
    scaleOrigin[2] = obj.scaleOrigin[2];

    scaleX = obj.scaleX;
    scaleY = obj.scaleY;
    scaleZ = obj.scaleZ;
    doTranslate = obj.doTranslate;
    translateX = obj.translateX;
    translateY = obj.translateY;
    translateZ = obj.translateZ;

    SelectAll();
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::~SimilarityTransformAttributes
//
// Purpose: 
//   Destructor for the SimilarityTransformAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SimilarityTransformAttributes::~SimilarityTransformAttributes()
{
    // nothing here
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::operator = 
//
// Purpose: 
//   Assignment operator for the SimilarityTransformAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SimilarityTransformAttributes& 
SimilarityTransformAttributes::operator = (const SimilarityTransformAttributes &obj)
{
    if (this == &obj) return *this;
    doRotate = obj.doRotate;
    rotateOrigin[0] = obj.rotateOrigin[0];
    rotateOrigin[1] = obj.rotateOrigin[1];
    rotateOrigin[2] = obj.rotateOrigin[2];

    rotateAxis[0] = obj.rotateAxis[0];
    rotateAxis[1] = obj.rotateAxis[1];
    rotateAxis[2] = obj.rotateAxis[2];

    rotateAmount = obj.rotateAmount;
    rotateType = obj.rotateType;
    doScale = obj.doScale;
    scaleOrigin[0] = obj.scaleOrigin[0];
    scaleOrigin[1] = obj.scaleOrigin[1];
    scaleOrigin[2] = obj.scaleOrigin[2];

    scaleX = obj.scaleX;
    scaleY = obj.scaleY;
    scaleZ = obj.scaleZ;
    doTranslate = obj.doTranslate;
    translateX = obj.translateX;
    translateY = obj.translateY;
    translateZ = obj.translateZ;

    SelectAll();
    return *this;
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::operator == 
//
// Purpose: 
//   Comparison operator == for the SimilarityTransformAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SimilarityTransformAttributes::operator == (const SimilarityTransformAttributes &obj) const
{
    // Compare the rotateOrigin arrays.
    bool rotateOrigin_equal = true;
    for(int i = 0; i < 3 && rotateOrigin_equal; ++i)
        rotateOrigin_equal = (rotateOrigin[i] == obj.rotateOrigin[i]);

    // Compare the rotateAxis arrays.
    bool rotateAxis_equal = true;
    for(int i = 0; i < 3 && rotateAxis_equal; ++i)
        rotateAxis_equal = (rotateAxis[i] == obj.rotateAxis[i]);

    // Compare the scaleOrigin arrays.
    bool scaleOrigin_equal = true;
    for(int i = 0; i < 3 && scaleOrigin_equal; ++i)
        scaleOrigin_equal = (scaleOrigin[i] == obj.scaleOrigin[i]);

    // Create the return value
    return ((doRotate == obj.doRotate) &&
            rotateOrigin_equal &&
            rotateAxis_equal &&
            (rotateAmount == obj.rotateAmount) &&
            (rotateType == obj.rotateType) &&
            (doScale == obj.doScale) &&
            scaleOrigin_equal &&
            (scaleX == obj.scaleX) &&
            (scaleY == obj.scaleY) &&
            (scaleZ == obj.scaleZ) &&
            (doTranslate == obj.doTranslate) &&
            (translateX == obj.translateX) &&
            (translateY == obj.translateY) &&
            (translateZ == obj.translateZ));
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::operator != 
//
// Purpose: 
//   Comparison operator != for the SimilarityTransformAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SimilarityTransformAttributes::operator != (const SimilarityTransformAttributes &obj) const
{
    return !(this->operator == (obj));
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::TypeName
//
// Purpose: 
//   Type name method for the SimilarityTransformAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

const std::string
SimilarityTransformAttributes::TypeName() const
{
    return "SimilarityTransformAttributes";
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::CopyAttributes
//
// Purpose: 
//   CopyAttributes method for the SimilarityTransformAttributes class.
//
// Programmer: Brad Whitlock
// Creation:   Tue Oct 29 08:57:18 PDT 2002
//
// Modifications:
//
// ****************************************************************************

bool
SimilarityTransformAttributes::CopyAttributes(const AttributeGroup *atts)
{
    bool retval = false;

    if(TypeName() == atts->TypeName())
    {
        // Call assignment operator.
        const SimilarityTransformAttributes *tmp = (const SimilarityTransformAttributes *)atts;
        *this = *tmp;
        retval = true;
    }
    else if(atts->TypeName() == "BoxExtents")
    {
        const BoxExtents *tmp = (const BoxExtents *)atts;
        const double *extents = tmp->GetExtents();
        if(doTranslate)
        {
            SetTranslateX(extents[0]);
            SetTranslateY(extents[2]);
            SetTranslateZ(extents[4]);
            retval = true;
        }
    }

    return retval;
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::CreateCompatible
//
// Purpose: 
//   Creates an object of the specified type initialized with the attributes
//   from this object.
//
// Arguments:
//   tname : The typename of the object that we want to create.
//
// Returns:    A new object of the type specified by tname or 0.
//
// Note:       
//
// Programmer: Brad Whitlock
// Creation:   Tue Oct 29 08:57:46 PDT 2002
//
// Modifications:
//   
// ****************************************************************************

AttributeSubject *
SimilarityTransformAttributes::CreateCompatible(const std::string &tname) const
{
    AttributeSubject *retval = 0;

    if(TypeName() == tname)
    {
        retval = new SimilarityTransformAttributes(*this);
    }
    else if(tname == "BoxExtents")
    {
        BoxExtents *b = new BoxExtents;
        double extents[6];
        extents[0] = translateX;
        extents[1] = translateX + 1.;
        extents[2] = translateY;
        extents[3] = translateY + 1.;
        extents[4] = translateZ;
        extents[5] = translateZ + 1.;
        b->SetExtents(extents);

        retval = b;
    }

    return retval;
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::NewInstance
//
// Purpose: 
//   NewInstance method for the SimilarityTransformAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

AttributeSubject *
SimilarityTransformAttributes::NewInstance(bool copy) const
{
    AttributeSubject *retval = 0;
    if(copy)
        retval = new SimilarityTransformAttributes(*this);
    else
        retval = new SimilarityTransformAttributes;

    return retval;
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::SelectAll
//
// Purpose: 
//   Selects all attributes.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
SimilarityTransformAttributes::SelectAll()
{
    Select(ID_doRotate,     (void *)&doRotate);
    Select(ID_rotateOrigin, (void *)rotateOrigin, 3);
    Select(ID_rotateAxis,   (void *)rotateAxis, 3);
    Select(ID_rotateAmount, (void *)&rotateAmount);
    Select(ID_rotateType,   (void *)&rotateType);
    Select(ID_doScale,      (void *)&doScale);
    Select(ID_scaleOrigin,  (void *)scaleOrigin, 3);
    Select(ID_scaleX,       (void *)&scaleX);
    Select(ID_scaleY,       (void *)&scaleY);
    Select(ID_scaleZ,       (void *)&scaleZ);
    Select(ID_doTranslate,  (void *)&doTranslate);
    Select(ID_translateX,   (void *)&translateX);
    Select(ID_translateY,   (void *)&translateY);
    Select(ID_translateZ,   (void *)&translateZ);
}

///////////////////////////////////////////////////////////////////////////////
// Persistence methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: SimilarityTransformAttributes::CreateNode
//
// Purpose: 
//   This method creates a DataNode representation of the object so it can be saved to a config file.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SimilarityTransformAttributes::CreateNode(DataNode *parentNode, bool completeSave, bool forceAdd)
{
    if(parentNode == 0)
        return false;

    SimilarityTransformAttributes defaultObject;
    bool addToParent = false;
    // Create a node for SimilarityTransformAttributes.
    DataNode *node = new DataNode("SimilarityTransformAttributes");

    if(completeSave || !FieldsEqual(ID_doRotate, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("doRotate", doRotate));
    }

    if(completeSave || !FieldsEqual(ID_rotateOrigin, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("rotateOrigin", rotateOrigin, 3));
    }

    if(completeSave || !FieldsEqual(ID_rotateAxis, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("rotateAxis", rotateAxis, 3));
    }

    if(completeSave || !FieldsEqual(ID_rotateAmount, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("rotateAmount", rotateAmount));
    }

    if(completeSave || !FieldsEqual(ID_rotateType, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("rotateType", AngleType_ToString(rotateType)));
    }

    if(completeSave || !FieldsEqual(ID_doScale, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("doScale", doScale));
    }

    if(completeSave || !FieldsEqual(ID_scaleOrigin, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("scaleOrigin", scaleOrigin, 3));
    }

    if(completeSave || !FieldsEqual(ID_scaleX, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("scaleX", scaleX));
    }

    if(completeSave || !FieldsEqual(ID_scaleY, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("scaleY", scaleY));
    }

    if(completeSave || !FieldsEqual(ID_scaleZ, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("scaleZ", scaleZ));
    }

    if(completeSave || !FieldsEqual(ID_doTranslate, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("doTranslate", doTranslate));
    }

    if(completeSave || !FieldsEqual(ID_translateX, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("translateX", translateX));
    }

    if(completeSave || !FieldsEqual(ID_translateY, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("translateY", translateY));
    }

    if(completeSave || !FieldsEqual(ID_translateZ, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("translateZ", translateZ));
    }


    // Add the node to the parent node.
    if(addToParent || forceAdd)
        parentNode->AddNode(node);
    else
        delete node;

    return (addToParent || forceAdd);
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::SetFromNode
//
// Purpose: 
//   This method sets attributes in this object from values in a DataNode representation of the object.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
SimilarityTransformAttributes::SetFromNode(DataNode *parentNode)
{
    if(parentNode == 0)
        return;

    DataNode *searchNode = parentNode->GetNode("SimilarityTransformAttributes");
    if(searchNode == 0)
        return;

    DataNode *node;
    if((node = searchNode->GetNode("doRotate")) != 0)
        SetDoRotate(node->AsBool());
    if((node = searchNode->GetNode("rotateOrigin")) != 0)
        SetRotateOrigin(node->AsFloatArray());
    if((node = searchNode->GetNode("rotateAxis")) != 0)
        SetRotateAxis(node->AsFloatArray());
    if((node = searchNode->GetNode("rotateAmount")) != 0)
        SetRotateAmount(node->AsFloat());
    if((node = searchNode->GetNode("rotateType")) != 0)
    {
        // Allow enums to be int or string in the config file
        if(node->GetNodeType() == INT_NODE)
        {
            int ival = node->AsInt();
            if(ival >= 0 && ival < 2)
                SetRotateType(AngleType(ival));
        }
        else if(node->GetNodeType() == STRING_NODE)
        {
            AngleType value;
            if(AngleType_FromString(node->AsString(), value))
                SetRotateType(value);
        }
    }
    if((node = searchNode->GetNode("doScale")) != 0)
        SetDoScale(node->AsBool());
    if((node = searchNode->GetNode("scaleOrigin")) != 0)
        SetScaleOrigin(node->AsFloatArray());
    if((node = searchNode->GetNode("scaleX")) != 0)
        SetScaleX(node->AsFloat());
    if((node = searchNode->GetNode("scaleY")) != 0)
        SetScaleY(node->AsFloat());
    if((node = searchNode->GetNode("scaleZ")) != 0)
        SetScaleZ(node->AsFloat());
    if((node = searchNode->GetNode("doTranslate")) != 0)
        SetDoTranslate(node->AsBool());
    if((node = searchNode->GetNode("translateX")) != 0)
        SetTranslateX(node->AsFloat());
    if((node = searchNode->GetNode("translateY")) != 0)
        SetTranslateY(node->AsFloat());
    if((node = searchNode->GetNode("translateZ")) != 0)
        SetTranslateZ(node->AsFloat());
}

///////////////////////////////////////////////////////////////////////////////
// Set property methods
///////////////////////////////////////////////////////////////////////////////

void
SimilarityTransformAttributes::SetDoRotate(bool doRotate_)
{
    doRotate = doRotate_;
    Select(ID_doRotate, (void *)&doRotate);
}

void
SimilarityTransformAttributes::SetRotateOrigin(const float *rotateOrigin_)
{
    rotateOrigin[0] = rotateOrigin_[0];
    rotateOrigin[1] = rotateOrigin_[1];
    rotateOrigin[2] = rotateOrigin_[2];
    Select(ID_rotateOrigin, (void *)rotateOrigin, 3);
}

void
SimilarityTransformAttributes::SetRotateAxis(const float *rotateAxis_)
{
    rotateAxis[0] = rotateAxis_[0];
    rotateAxis[1] = rotateAxis_[1];
    rotateAxis[2] = rotateAxis_[2];
    Select(ID_rotateAxis, (void *)rotateAxis, 3);
}

void
SimilarityTransformAttributes::SetRotateAmount(float rotateAmount_)
{
    rotateAmount = rotateAmount_;
    Select(ID_rotateAmount, (void *)&rotateAmount);
}

void
SimilarityTransformAttributes::SetRotateType(SimilarityTransformAttributes::AngleType rotateType_)
{
    rotateType = rotateType_;
    Select(ID_rotateType, (void *)&rotateType);
}

void
SimilarityTransformAttributes::SetDoScale(bool doScale_)
{
    doScale = doScale_;
    Select(ID_doScale, (void *)&doScale);
}

void
SimilarityTransformAttributes::SetScaleOrigin(const float *scaleOrigin_)
{
    scaleOrigin[0] = scaleOrigin_[0];
    scaleOrigin[1] = scaleOrigin_[1];
    scaleOrigin[2] = scaleOrigin_[2];
    Select(ID_scaleOrigin, (void *)scaleOrigin, 3);
}

void
SimilarityTransformAttributes::SetScaleX(float scaleX_)
{
    scaleX = scaleX_;
    Select(ID_scaleX, (void *)&scaleX);
}

void
SimilarityTransformAttributes::SetScaleY(float scaleY_)
{
    scaleY = scaleY_;
    Select(ID_scaleY, (void *)&scaleY);
}

void
SimilarityTransformAttributes::SetScaleZ(float scaleZ_)
{
    scaleZ = scaleZ_;
    Select(ID_scaleZ, (void *)&scaleZ);
}

void
SimilarityTransformAttributes::SetDoTranslate(bool doTranslate_)
{
    doTranslate = doTranslate_;
    Select(ID_doTranslate, (void *)&doTranslate);
}

void
SimilarityTransformAttributes::SetTranslateX(float translateX_)
{
    translateX = translateX_;
    Select(ID_translateX, (void *)&translateX);
}

void
SimilarityTransformAttributes::SetTranslateY(float translateY_)
{
    translateY = translateY_;
    Select(ID_translateY, (void *)&translateY);
}

void
SimilarityTransformAttributes::SetTranslateZ(float translateZ_)
{
    translateZ = translateZ_;
    Select(ID_translateZ, (void *)&translateZ);
}

///////////////////////////////////////////////////////////////////////////////
// Get property methods
///////////////////////////////////////////////////////////////////////////////

bool
SimilarityTransformAttributes::GetDoRotate() const
{
    return doRotate;
}

const float *
SimilarityTransformAttributes::GetRotateOrigin() const
{
    return rotateOrigin;
}

float *
SimilarityTransformAttributes::GetRotateOrigin()
{
    return rotateOrigin;
}

const float *
SimilarityTransformAttributes::GetRotateAxis() const
{
    return rotateAxis;
}

float *
SimilarityTransformAttributes::GetRotateAxis()
{
    return rotateAxis;
}

float
SimilarityTransformAttributes::GetRotateAmount() const
{
    return rotateAmount;
}

SimilarityTransformAttributes::AngleType
SimilarityTransformAttributes::GetRotateType() const
{
    return AngleType(rotateType);
}

bool
SimilarityTransformAttributes::GetDoScale() const
{
    return doScale;
}

const float *
SimilarityTransformAttributes::GetScaleOrigin() const
{
    return scaleOrigin;
}

float *
SimilarityTransformAttributes::GetScaleOrigin()
{
    return scaleOrigin;
}

float
SimilarityTransformAttributes::GetScaleX() const
{
    return scaleX;
}

float
SimilarityTransformAttributes::GetScaleY() const
{
    return scaleY;
}

float
SimilarityTransformAttributes::GetScaleZ() const
{
    return scaleZ;
}

bool
SimilarityTransformAttributes::GetDoTranslate() const
{
    return doTranslate;
}

float
SimilarityTransformAttributes::GetTranslateX() const
{
    return translateX;
}

float
SimilarityTransformAttributes::GetTranslateY() const
{
    return translateY;
}

float
SimilarityTransformAttributes::GetTranslateZ() const
{
    return translateZ;
}

///////////////////////////////////////////////////////////////////////////////
// Select property methods
///////////////////////////////////////////////////////////////////////////////

void
SimilarityTransformAttributes::SelectRotateOrigin()
{
    Select(ID_rotateOrigin, (void *)rotateOrigin, 3);
}

void
SimilarityTransformAttributes::SelectRotateAxis()
{
    Select(ID_rotateAxis, (void *)rotateAxis, 3);
}

void
SimilarityTransformAttributes::SelectScaleOrigin()
{
    Select(ID_scaleOrigin, (void *)scaleOrigin, 3);
}

///////////////////////////////////////////////////////////////////////////////
// Keyframing methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: SimilarityTransformAttributes::GetFieldName
//
// Purpose: 
//   This method returns the name of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

std::string
SimilarityTransformAttributes::GetFieldName(int index) const
{
    switch (index)
    {
    case ID_doRotate:     return "doRotate";
    case ID_rotateOrigin: return "rotateOrigin";
    case ID_rotateAxis:   return "rotateAxis";
    case ID_rotateAmount: return "rotateAmount";
    case ID_rotateType:   return "rotateType";
    case ID_doScale:      return "doScale";
    case ID_scaleOrigin:  return "scaleOrigin";
    case ID_scaleX:       return "scaleX";
    case ID_scaleY:       return "scaleY";
    case ID_scaleZ:       return "scaleZ";
    case ID_doTranslate:  return "doTranslate";
    case ID_translateX:   return "translateX";
    case ID_translateY:   return "translateY";
    case ID_translateZ:   return "translateZ";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::GetFieldType
//
// Purpose: 
//   This method returns the type of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

AttributeGroup::FieldType
SimilarityTransformAttributes::GetFieldType(int index) const
{
    switch (index)
    {
    case ID_doRotate:     return FieldType_bool;
    case ID_rotateOrigin: return FieldType_floatArray;
    case ID_rotateAxis:   return FieldType_floatArray;
    case ID_rotateAmount: return FieldType_float;
    case ID_rotateType:   return FieldType_enum;
    case ID_doScale:      return FieldType_bool;
    case ID_scaleOrigin:  return FieldType_floatArray;
    case ID_scaleX:       return FieldType_float;
    case ID_scaleY:       return FieldType_float;
    case ID_scaleZ:       return FieldType_float;
    case ID_doTranslate:  return FieldType_bool;
    case ID_translateX:   return FieldType_float;
    case ID_translateY:   return FieldType_float;
    case ID_translateZ:   return FieldType_float;
    default:  return FieldType_unknown;
    }
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::GetFieldTypeName
//
// Purpose: 
//   This method returns the name of a field type given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

std::string
SimilarityTransformAttributes::GetFieldTypeName(int index) const
{
    switch (index)
    {
    case ID_doRotate:     return "bool";
    case ID_rotateOrigin: return "floatArray";
    case ID_rotateAxis:   return "floatArray";
    case ID_rotateAmount: return "float";
    case ID_rotateType:   return "enum";
    case ID_doScale:      return "bool";
    case ID_scaleOrigin:  return "floatArray";
    case ID_scaleX:       return "float";
    case ID_scaleY:       return "float";
    case ID_scaleZ:       return "float";
    case ID_doTranslate:  return "bool";
    case ID_translateX:   return "float";
    case ID_translateY:   return "float";
    case ID_translateZ:   return "float";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: SimilarityTransformAttributes::FieldsEqual
//
// Purpose: 
//   This method compares two fields and return true if they are equal.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SimilarityTransformAttributes::FieldsEqual(int index_, const AttributeGroup *rhs) const
{
    const SimilarityTransformAttributes &obj = *((const SimilarityTransformAttributes*)rhs);
    bool retval = false;
    switch (index_)
    {
    case ID_doRotate:
        {  // new scope
        retval = (doRotate == obj.doRotate);
        }
        break;
    case ID_rotateOrigin:
        {  // new scope
        // Compare the rotateOrigin arrays.
        bool rotateOrigin_equal = true;
        for(int i = 0; i < 3 && rotateOrigin_equal; ++i)
            rotateOrigin_equal = (rotateOrigin[i] == obj.rotateOrigin[i]);

        retval = rotateOrigin_equal;
        }
        break;
    case ID_rotateAxis:
        {  // new scope
        // Compare the rotateAxis arrays.
        bool rotateAxis_equal = true;
        for(int i = 0; i < 3 && rotateAxis_equal; ++i)
            rotateAxis_equal = (rotateAxis[i] == obj.rotateAxis[i]);

        retval = rotateAxis_equal;
        }
        break;
    case ID_rotateAmount:
        {  // new scope
        retval = (rotateAmount == obj.rotateAmount);
        }
        break;
    case ID_rotateType:
        {  // new scope
        retval = (rotateType == obj.rotateType);
        }
        break;
    case ID_doScale:
        {  // new scope
        retval = (doScale == obj.doScale);
        }
        break;
    case ID_scaleOrigin:
        {  // new scope
        // Compare the scaleOrigin arrays.
        bool scaleOrigin_equal = true;
        for(int i = 0; i < 3 && scaleOrigin_equal; ++i)
            scaleOrigin_equal = (scaleOrigin[i] == obj.scaleOrigin[i]);

        retval = scaleOrigin_equal;
        }
        break;
    case ID_scaleX:
        {  // new scope
        retval = (scaleX == obj.scaleX);
        }
        break;
    case ID_scaleY:
        {  // new scope
        retval = (scaleY == obj.scaleY);
        }
        break;
    case ID_scaleZ:
        {  // new scope
        retval = (scaleZ == obj.scaleZ);
        }
        break;
    case ID_doTranslate:
        {  // new scope
        retval = (doTranslate == obj.doTranslate);
        }
        break;
    case ID_translateX:
        {  // new scope
        retval = (translateX == obj.translateX);
        }
        break;
    case ID_translateY:
        {  // new scope
        retval = (translateY == obj.translateY);
        }
        break;
    case ID_translateZ:
        {  // new scope
        retval = (translateZ == obj.translateZ);
        }
        break;
    default: retval = false;
    }

    return retval;
}

///////////////////////////////////////////////////////////////////////////////
// User-defined methods.
///////////////////////////////////////////////////////////////////////////////

