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

#ifndef INTERACTORATTRIBUTES_H
#define INTERACTORATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>


// ****************************************************************************
// Class: InteractorAttributes
//
// Purpose:
//    This class contains attributes associated with the main window.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API InteractorAttributes : public AttributeSubject
{
public:
    enum NavigationMode
    {
        Trackball,
        Dolly,
        Flythrough
    };
    enum BoundingBoxMode
    {
        Always,
        Never,
        Auto
    };

    // These constructors are for objects of this class
    InteractorAttributes();
    InteractorAttributes(const InteractorAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    InteractorAttributes(private_tmfs_t tmfs);
    InteractorAttributes(const InteractorAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~InteractorAttributes();

    virtual InteractorAttributes& operator = (const InteractorAttributes &obj);
    virtual bool operator == (const InteractorAttributes &obj) const;
    virtual bool operator != (const InteractorAttributes &obj) const;
private:
    void Init();
    void Copy(const InteractorAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();

    // Property setting methods
    void SetShowGuidelines(bool showGuidelines_);
    void SetClampSquare(bool clampSquare_);
    void SetFillViewportOnZoom(bool fillViewportOnZoom_);
    void SetNavigationMode(NavigationMode navigationMode_);
    void SetAxisArraySnap(bool axisArraySnap_);
    void SetBoundingBoxMode(BoundingBoxMode boundingBoxMode_);

    // Property getting methods
    bool GetShowGuidelines() const;
    bool GetClampSquare() const;
    bool GetFillViewportOnZoom() const;
    NavigationMode GetNavigationMode() const;
    bool GetAxisArraySnap() const;
    BoundingBoxMode GetBoundingBoxMode() const;

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string NavigationMode_ToString(NavigationMode);
    static bool NavigationMode_FromString(const std::string &, NavigationMode &);
protected:
    static std::string NavigationMode_ToString(int);
public:
    static std::string BoundingBoxMode_ToString(BoundingBoxMode);
    static bool BoundingBoxMode_FromString(const std::string &, BoundingBoxMode &);
protected:
    static std::string BoundingBoxMode_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_showGuidelines = 0,
        ID_clampSquare,
        ID_fillViewportOnZoom,
        ID_navigationMode,
        ID_axisArraySnap,
        ID_boundingBoxMode,
        ID__LAST
    };

private:
    bool showGuidelines;
    bool clampSquare;
    bool fillViewportOnZoom;
    int  navigationMode;
    bool axisArraySnap;
    int  boundingBoxMode;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define INTERACTORATTRIBUTES_TMFS "bbbibi"

#endif
