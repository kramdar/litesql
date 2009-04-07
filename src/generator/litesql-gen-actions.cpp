/* XML application for litesql.dtd.
 * Includes actions from litesql-gen.xml.
 * Generated 2005/12/06 13:13:10.
 *
 * This program was generated with the FleXML XML processor generator.
 * FleXML is Copyright � 1999-2005 Kristoffer Rose.  All rights reserved.
 * (Id: flexml.pl,v 1.44 2005/02/23 23:08:16 mquinson Exp).
 * 
 * There are two, intertwined parts to this program, part A and part B.
 *
 * Part A
 * ------
 * 
 * Some parts, here collectively called "Part A", are found in the 
 * FleXML package.  They are Copyright � 1999-2005 Kristoffer Rose. 
 * All rights reserved.
 *
 * You can redistribute, use, perform, display and/or modify "Part A"
 * provided the following two conditions hold:
 *
 * 1. The program is distributed WITHOUT ANY WARRANTY from the author of
 *    FleXML; without even the implied warranty of MERCHANTABILITY or
 *    FITNESS FOR A PARTICULAR PURPOSE.
 *
 * 2. The program distribution conditions do not in any way affect the
 *    distribution conditions of the FleXML system used to generate this
 *    file or any version of FleXML derived from that system.
 *
 * Notice that these are explicit rights granted to you for files
 * generated by the FleXML system.  For your rights in connection with
 * the FleXML system itself please consult the GNU General Public License.
 * 
 * Part B
 * ------
 * 
 * The other parts, here collectively called "Part B", and which came 
 * from the DTD used by FleXML to generate this program, can be 
 * distributed (or not, as the case may be) under the terms of whoever
 * wrote them, provided these terms respect and obey the two conditions 
 * above under the heading "Part A".
 *
 * The author of and contributors to FleXML specifically disclaim
 * any copyright interest in "Part B", unless "Part B" was written 
 * by the author of or contributors to FleXML.
 * 
 */

#include "litesql-gen.hpp"


#line 3 "litesql-gen.xml"

#include "objectmodel.hpp"
#include "xmlobjects.hpp"
#include "litesql-gen-main.hpp"
#include "litesql-gen.hpp"

using namespace std;
using namespace xml;

ObjectModel model;

/*
vector<Object*> objects;
vector<Relation*> relations;
Database db;
*/
Object * obj;
Relation * rel;
Field * fld;
Method * mtd;
Index * idx;

void STag_database(void)
{
#line 19 "litesql-gen.xml"

model.db.name = safe(A_database_name);
model.db.include = safe(A_database_include);
model.db.nspace = safe(A_database_namespace);

} /* STag_database */

void STag_object(void)
{
#line 24 "litesql-gen.xml"

model.objects.push_back(obj = new Object(A_object_name, safe(A_object_inherits)));

} /* STag_object */

void ETag_object(void)
{
#line 27 "litesql-gen.xml"

obj = NULL;

} /* ETag_object */

void STag_relation(void)
{
#line 30 "litesql-gen.xml"

model.relations.push_back(rel = new Relation(safe(A_relation_id), safe(A_relation_name),A_relation_unidir));

} /* STag_relation */

void ETag_relation(void)
{
#line 33 "litesql-gen.xml"

rel = NULL;

} /* ETag_relation */

void STag_field(void)
{
#line 36 "litesql-gen.xml"

if (obj) {
    obj->fields.push_back(fld =new Field(A_field_name, 
                                     A_field_type,safe(A_field_default),A_field_indexed,A_field_unique));
} else if (rel) {
    rel->fields.push_back(fld = new Field(A_field_name, 
                         A_field_type,safe(A_field_default),A_field_indexed, A_field_unique));
}

} /* STag_field */

void STag_index(void)
{
#line 45 "litesql-gen.xml"

idx = new Index(A_index_unique);
if (obj) 
    obj->indices.push_back(idx);
else if (rel) 
    rel->indices.push_back(idx);

} /* STag_index */

void ETag_index(void)
{
#line 52 "litesql-gen.xml"

idx = NULL;

} /* ETag_index */

void STag_indexfield(void)
{
#line 55 "litesql-gen.xml"

if (idx)
    idx->fields.push_back(IndexField(A_indexfield_name));

} /* STag_indexfield */

void STag_value(void)
{
#line 59 "litesql-gen.xml"

if (fld) 
    fld->value(Value(A_value_name, A_value_value));

} /* STag_value */

void ETag_field(void)
{
#line 63 "litesql-gen.xml"

fld = NULL;

} /* ETag_field */

void STag_method(void)
{
#line 66 "litesql-gen.xml"

if (obj) {
    obj->methods.push_back(mtd = new Method(A_method_name, safe(A_method_returntype)));
}

} /* STag_method */

void ETag_method(void)
{
#line 71 "litesql-gen.xml"

mtd = NULL;

} /* ETag_method */

void STag_param(void)
{
#line 74 "litesql-gen.xml"

if (mtd) 
    mtd->param(Param(A_param_name, A_param_type));

} /* STag_param */

void STag_relate(void)
{
#line 78 "litesql-gen.xml"

if (rel)
    rel->related.push_back(new Relate(A_relate_object, A_relate_limit, A_relate_unique, safe(A_relate_handle)));

} /* STag_relate */

void ETag_database(void)
{
#line 82 "litesql-gen.xml"

    generateCode(model.db, model.objects, model.relations);    

} /* ETag_database */


#line 90 "litesql-gen.xml"

extern FILE * yyin;
int main(int argc, char **argv) {
    return litesql_gen_main(argc, argv, &yyin);
}


/* XML application entry points. */
void ETag_indexfield(void) {}
void ETag_value(void) {}
void ETag_param(void) {}
void ETag_relate(void) {}
