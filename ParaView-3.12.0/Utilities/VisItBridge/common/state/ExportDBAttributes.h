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

#ifndef EXPORTDBATTRIBUTES_H
#define EXPORTDBATTRIBUTES_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>
#include <DBOptionsAttributes.h>

// ****************************************************************************
// Class: ExportDBAttributes
//
// Purpose:
//    The attributes for export a database
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class STATE_API ExportDBAttributes : public AttributeSubject
{
public:
    ExportDBAttributes();
    ExportDBAttributes(const ExportDBAttributes &obj);
    virtual ~ExportDBAttributes();

    virtual ExportDBAttributes& operator = (const ExportDBAttributes &obj);
    virtual bool operator == (const ExportDBAttributes &obj) const;
    virtual bool operator != (const ExportDBAttributes &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectDb_type();
    void SelectDb_type_fullname();
    void SelectFilename();
    void SelectDirname();
    void SelectVariables();
    void SelectOpts();

    // Property setting methods
    void SetDb_type(const std::string &db_type_);
    void SetDb_type_fullname(const std::string &db_type_fullname_);
    void SetFilename(const std::string &filename_);
    void SetDirname(const std::string &dirname_);
    void SetVariables(const stringVector &variables_);
    void SetOpts(const DBOptionsAttributes &opts_);

    // Property getting methods
    const std::string         &GetDb_type() const;
          std::string         &GetDb_type();
    const std::string         &GetDb_type_fullname() const;
          std::string         &GetDb_type_fullname();
    const std::string         &GetFilename() const;
          std::string         &GetFilename();
    const std::string         &GetDirname() const;
          std::string         &GetDirname();
    const stringVector        &GetVariables() const;
          stringVector        &GetVariables();
    const DBOptionsAttributes &GetOpts() const;
          DBOptionsAttributes &GetOpts();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool completeSave, bool forceAdd);
    virtual void SetFromNode(DataNode *node);


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;


    // IDs that can be used to identify fields in case statements
    enum {
        ID_db_type = 0,
        ID_db_type_fullname,
        ID_filename,
        ID_dirname,
        ID_variables,
        ID_opts
    };

private:
    std::string         db_type;
    std::string         db_type_fullname;
    std::string         filename;
    std::string         dirname;
    stringVector        variables;
    DBOptionsAttributes opts;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
};

#endif
