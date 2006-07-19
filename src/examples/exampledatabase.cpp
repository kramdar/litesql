#include "exampledatabase.hpp"
namespace example {
using namespace litesql;
Expressions::Person Expressions::Person::operator!() const {
    return Expressions::Person(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::Role Expressions::Role::operator!() const {
    return Expressions::Role(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::School Expressions::School::operator!() const {
    return Expressions::School(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::Office Expressions::Office::operator!() const {
    return Expressions::Office(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::PersonPersonRelationMother Expressions::PersonPersonRelationMother::operator!() const {
    return Expressions::PersonPersonRelationMother(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::PersonPersonRelationFather Expressions::PersonPersonRelationFather::operator!() const {
    return Expressions::PersonPersonRelationFather(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::PersonPersonRelationSiblings Expressions::PersonPersonRelationSiblings::operator!() const {
    return Expressions::PersonPersonRelationSiblings(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::PersonPersonRelationChildren Expressions::PersonPersonRelationChildren::operator!() const {
    return Expressions::PersonPersonRelationChildren(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::RoleRelation Expressions::RoleRelation::operator!() const {
    return Expressions::RoleRelation(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::SchoolStudentRelation Expressions::SchoolStudentRelation::operator!() const {
    return Expressions::SchoolStudentRelation(litesql::Not(litesql::RawExpr(expr)));
}
Expressions::EmployeeOfficeRelation Expressions::EmployeeOfficeRelation::operator!() const {
    return Expressions::EmployeeOfficeRelation(litesql::Not(litesql::RawExpr(expr)));
}
RowTypes::PersonPersonRelationMotherRow::PersonPersonRelationMotherRow(const litesql::Database& db, const litesql::Record& rec)
         : person2(PersonPersonRelationMother::Person2), person1(PersonPersonRelationMother::Person1) {
    switch(rec.size()) {
    case 2:
        person2 = rec[1];
    case 1:
        person1 = rec[0];
    }
}
RowTypes::PersonPersonRelationFatherRow::PersonPersonRelationFatherRow(const litesql::Database& db, const litesql::Record& rec)
         : person2(PersonPersonRelationFather::Person2), person1(PersonPersonRelationFather::Person1) {
    switch(rec.size()) {
    case 2:
        person2 = rec[1];
    case 1:
        person1 = rec[0];
    }
}
RowTypes::PersonPersonRelationSiblingsRow::PersonPersonRelationSiblingsRow(const litesql::Database& db, const litesql::Record& rec)
         : person2(PersonPersonRelationSiblings::Person2), person1(PersonPersonRelationSiblings::Person1) {
    switch(rec.size()) {
    case 2:
        person2 = rec[1];
    case 1:
        person1 = rec[0];
    }
}
RowTypes::PersonPersonRelationChildrenRow::PersonPersonRelationChildrenRow(const litesql::Database& db, const litesql::Record& rec)
         : person2(PersonPersonRelationChildren::Person2), person1(PersonPersonRelationChildren::Person1) {
    switch(rec.size()) {
    case 2:
        person2 = rec[1];
    case 1:
        person1 = rec[0];
    }
}
RowTypes::RoleRelationRow::RoleRelationRow(const litesql::Database& db, const litesql::Record& rec)
         : role(RoleRelation::Role), person(RoleRelation::Person) {
    switch(rec.size()) {
    case 2:
        role = rec[1];
    case 1:
        person = rec[0];
    }
}
RowTypes::SchoolStudentRelationRow::SchoolStudentRelationRow(const litesql::Database& db, const litesql::Record& rec)
         : student(SchoolStudentRelation::Student), school(SchoolStudentRelation::School) {
    switch(rec.size()) {
    case 2:
        student = rec[1];
    case 1:
        school = rec[0];
    }
}
RowTypes::EmployeeOfficeRelationRow::EmployeeOfficeRelationRow(const litesql::Database& db, const litesql::Record& rec)
         : office(EmployeeOfficeRelation::Office), employee(EmployeeOfficeRelation::Employee) {
    switch(rec.size()) {
    case 2:
        office = rec[1];
    case 1:
        employee = rec[0];
    }
}
PersonPersonRelationMother::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const std::string PersonPersonRelationMother::table__("Person_Person_Mother");
const PersonPersonRelationMother::FieldType PersonPersonRelationMother::Person1("Person1","INTEGER",table__);
const PersonPersonRelationMother::FieldType PersonPersonRelationMother::Person2("Person2","INTEGER",table__);
void PersonPersonRelationMother::link(const litesql::Database& db, const example::Person& o0, const example::Person& o1) {
    Record values;
    Split fields;
    fields.push_back(Person1.name());
    values.push_back(o0.id);
    fields.push_back(Person2.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void PersonPersonRelationMother::unlink(const litesql::Database& db, const example::Person& o0, const example::Person& o1) {
    db.delete_(table__, (Person1 == o0.id && Person2 == o1.id));
}
void PersonPersonRelationMother::del(const litesql::Database& db, const PersonPersonRelationMother::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<PersonPersonRelationMother::Row> PersonPersonRelationMother::getRows(const litesql::Database& db, const PersonPersonRelationMother::Expr& expr) {
    SelectQuery sel;
    sel.result(Person1.fullName());
    sel.result(Person2.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<PersonPersonRelationMother::Row>(db, sel);
}
litesql::DataSource<example::Person> PersonPersonRelationMother::getPerson1(const litesql::Database& db, const Expressions::Person& expr, const Expressions::PersonPersonRelationMother& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person1.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
litesql::DataSource<example::Person> PersonPersonRelationMother::getPerson2(const litesql::Database& db, const Expressions::Person& expr, const Expressions::PersonPersonRelationMother& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person2.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
PersonPersonRelationFather::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const std::string PersonPersonRelationFather::table__("Person_Person_Father");
const PersonPersonRelationFather::FieldType PersonPersonRelationFather::Person1("Person1","INTEGER",table__);
const PersonPersonRelationFather::FieldType PersonPersonRelationFather::Person2("Person2","INTEGER",table__);
void PersonPersonRelationFather::link(const litesql::Database& db, const example::Person& o0, const example::Person& o1) {
    Record values;
    Split fields;
    fields.push_back(Person1.name());
    values.push_back(o0.id);
    fields.push_back(Person2.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void PersonPersonRelationFather::unlink(const litesql::Database& db, const example::Person& o0, const example::Person& o1) {
    db.delete_(table__, (Person1 == o0.id && Person2 == o1.id));
}
void PersonPersonRelationFather::del(const litesql::Database& db, const PersonPersonRelationFather::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<PersonPersonRelationFather::Row> PersonPersonRelationFather::getRows(const litesql::Database& db, const PersonPersonRelationFather::Expr& expr) {
    SelectQuery sel;
    sel.result(Person1.fullName());
    sel.result(Person2.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<PersonPersonRelationFather::Row>(db, sel);
}
litesql::DataSource<example::Person> PersonPersonRelationFather::getPerson1(const litesql::Database& db, const Expressions::Person& expr, const Expressions::PersonPersonRelationFather& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person1.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
litesql::DataSource<example::Person> PersonPersonRelationFather::getPerson2(const litesql::Database& db, const Expressions::Person& expr, const Expressions::PersonPersonRelationFather& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person2.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
PersonPersonRelationSiblings::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const std::string PersonPersonRelationSiblings::table__("Person_Person_Siblings");
const PersonPersonRelationSiblings::FieldType PersonPersonRelationSiblings::Person1("Person1","INTEGER",table__);
const PersonPersonRelationSiblings::FieldType PersonPersonRelationSiblings::Person2("Person2","INTEGER",table__);
void PersonPersonRelationSiblings::link(const litesql::Database& db, const example::Person& o0, const example::Person& o1) {
    Record values;
    Split fields;
    fields.push_back(Person1.name());
    values.push_back(o0.id);
    fields.push_back(Person2.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
    fields.clear();
    values.clear();
    fields.push_back(Person1.name());
    values.push_back(o1.id);
    fields.push_back(Person2.name());
    values.push_back(o0.id);
    db.insert(table__, values, fields);
}
void PersonPersonRelationSiblings::unlink(const litesql::Database& db, const example::Person& o0, const example::Person& o1) {
    db.delete_(table__, (Person1 == o0.id && Person2 == o1.id));
    db.delete_(table__, (Person1 == o1.id && Person2 == o0.id));
}
void PersonPersonRelationSiblings::del(const litesql::Database& db, const PersonPersonRelationSiblings::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<PersonPersonRelationSiblings::Row> PersonPersonRelationSiblings::getRows(const litesql::Database& db, const PersonPersonRelationSiblings::Expr& expr) {
    SelectQuery sel;
    sel.result(Person1.fullName());
    sel.result(Person2.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<PersonPersonRelationSiblings::Row>(db, sel);
}
litesql::DataSource<example::Person> PersonPersonRelationSiblings::getPerson1(const litesql::Database& db, const Expressions::Person& expr, const Expressions::PersonPersonRelationSiblings& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person1.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
litesql::DataSource<example::Person> PersonPersonRelationSiblings::getPerson2(const litesql::Database& db, const Expressions::Person& expr, const Expressions::PersonPersonRelationSiblings& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person2.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
PersonPersonRelationChildren::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const std::string PersonPersonRelationChildren::table__("Person_Person_Children");
const PersonPersonRelationChildren::FieldType PersonPersonRelationChildren::Person1("Person1","INTEGER",table__);
const PersonPersonRelationChildren::FieldType PersonPersonRelationChildren::Person2("Person2","INTEGER",table__);
void PersonPersonRelationChildren::link(const litesql::Database& db, const example::Person& o0, const example::Person& o1) {
    Record values;
    Split fields;
    fields.push_back(Person1.name());
    values.push_back(o0.id);
    fields.push_back(Person2.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void PersonPersonRelationChildren::unlink(const litesql::Database& db, const example::Person& o0, const example::Person& o1) {
    db.delete_(table__, (Person1 == o0.id && Person2 == o1.id));
}
void PersonPersonRelationChildren::del(const litesql::Database& db, const PersonPersonRelationChildren::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<PersonPersonRelationChildren::Row> PersonPersonRelationChildren::getRows(const litesql::Database& db, const PersonPersonRelationChildren::Expr& expr) {
    SelectQuery sel;
    sel.result(Person1.fullName());
    sel.result(Person2.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<PersonPersonRelationChildren::Row>(db, sel);
}
litesql::DataSource<example::Person> PersonPersonRelationChildren::getPerson1(const litesql::Database& db, const Expressions::Person& expr, const Expressions::PersonPersonRelationChildren& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person1.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
litesql::DataSource<example::Person> PersonPersonRelationChildren::getPerson2(const litesql::Database& db, const Expressions::Person& expr, const Expressions::PersonPersonRelationChildren& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person2.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
RoleRelation::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const std::string RoleRelation::table__("Person_Role_Roles");
const RoleRelation::FieldType RoleRelation::Person("Person1","INTEGER",table__);
const RoleRelation::FieldType RoleRelation::Role("Role2","INTEGER",table__);
void RoleRelation::link(const litesql::Database& db, const example::Person& o0, const example::Role& o1) {
    Record values;
    Split fields;
    fields.push_back(Person.name());
    values.push_back(o0.id);
    fields.push_back(Role.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void RoleRelation::unlink(const litesql::Database& db, const example::Person& o0, const example::Role& o1) {
    db.delete_(table__, (Person == o0.id && Role == o1.id));
}
void RoleRelation::del(const litesql::Database& db, const RoleRelation::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<RoleRelation::Row> RoleRelation::getRows(const litesql::Database& db, const RoleRelation::Expr& expr) {
    SelectQuery sel;
    sel.result(Person.fullName());
    sel.result(Role.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<RoleRelation::Row>(db, sel);
}
template <> litesql::DataSource<example::Person> RoleRelation::get(const litesql::Database& db, const Expressions::Person& expr, const Expressions::RoleRelation& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Person.fullName());
    sel.where(srcExpr);
    return DataSource<example::Person>(db, example::Person::Id.in(sel) && expr);
}
template <> litesql::DataSource<example::Role> RoleRelation::get(const litesql::Database& db, const Expressions::Role& expr, const Expressions::RoleRelation& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Role.fullName());
    sel.where(srcExpr);
    return DataSource<example::Role>(db, example::Role::Id.in(sel) && expr);
}
SchoolStudentRelation::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const std::string SchoolStudentRelation::table__("School_Student_");
const SchoolStudentRelation::FieldType SchoolStudentRelation::School("School1","INTEGER",table__);
const SchoolStudentRelation::FieldType SchoolStudentRelation::Student("Student2","INTEGER",table__);
void SchoolStudentRelation::link(const litesql::Database& db, const example::School& o0, const example::Student& o1) {
    Record values;
    Split fields;
    fields.push_back(School.name());
    values.push_back(o0.id);
    fields.push_back(Student.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void SchoolStudentRelation::unlink(const litesql::Database& db, const example::School& o0, const example::Student& o1) {
    db.delete_(table__, (School == o0.id && Student == o1.id));
}
void SchoolStudentRelation::del(const litesql::Database& db, const SchoolStudentRelation::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<SchoolStudentRelation::Row> SchoolStudentRelation::getRows(const litesql::Database& db, const SchoolStudentRelation::Expr& expr) {
    SelectQuery sel;
    sel.result(School.fullName());
    sel.result(Student.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<SchoolStudentRelation::Row>(db, sel);
}
template <> litesql::DataSource<example::School> SchoolStudentRelation::get(const litesql::Database& db, const Expressions::School& expr, const Expressions::SchoolStudentRelation& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(School.fullName());
    sel.where(srcExpr);
    return DataSource<example::School>(db, example::School::Id.in(sel) && expr);
}
template <> litesql::DataSource<example::Student> SchoolStudentRelation::get(const litesql::Database& db, const Expressions::Role& expr, const Expressions::SchoolStudentRelation& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Student.fullName());
    sel.where(srcExpr);
    return DataSource<example::Student>(db, example::Student::Id.in(sel) && expr);
}
EmployeeOfficeRelation::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const std::string EmployeeOfficeRelation::table__("Employee_Office_");
const EmployeeOfficeRelation::FieldType EmployeeOfficeRelation::Employee("Employee1","INTEGER",table__);
const EmployeeOfficeRelation::FieldType EmployeeOfficeRelation::Office("Office2","INTEGER",table__);
void EmployeeOfficeRelation::link(const litesql::Database& db, const example::Employee& o0, const example::Office& o1) {
    Record values;
    Split fields;
    fields.push_back(Employee.name());
    values.push_back(o0.id);
    fields.push_back(Office.name());
    values.push_back(o1.id);
    db.insert(table__, values, fields);
}
void EmployeeOfficeRelation::unlink(const litesql::Database& db, const example::Employee& o0, const example::Office& o1) {
    db.delete_(table__, (Employee == o0.id && Office == o1.id));
}
void EmployeeOfficeRelation::del(const litesql::Database& db, const EmployeeOfficeRelation::Expr& expr) {
    db.delete_(table__, expr);
}
litesql::DataSource<EmployeeOfficeRelation::Row> EmployeeOfficeRelation::getRows(const litesql::Database& db, const EmployeeOfficeRelation::Expr& expr) {
    SelectQuery sel;
    sel.result(Employee.fullName());
    sel.result(Office.fullName());
    sel.source(table__);
    sel.where(expr);
    return DataSource<EmployeeOfficeRelation::Row>(db, sel);
}
template <> litesql::DataSource<example::Employee> EmployeeOfficeRelation::get(const litesql::Database& db, const Expressions::Role& expr, const Expressions::EmployeeOfficeRelation& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Employee.fullName());
    sel.where(srcExpr);
    return DataSource<example::Employee>(db, example::Employee::Id.in(sel) && expr);
}
template <> litesql::DataSource<example::Office> EmployeeOfficeRelation::get(const litesql::Database& db, const Expressions::Office& expr, const Expressions::EmployeeOfficeRelation& srcExpr) {
    SelectQuery sel;
    sel.source(table__);
    sel.result(Office.fullName());
    sel.where(srcExpr);
    return DataSource<example::Office>(db, example::Office::Id.in(sel) && expr);
}
Person::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const Person::FieldType Person::Own::Id("id_","INTEGER","Person_");
const int Person::Sex::Male(0);
const int Person::Sex::Female(1);
Person::MotherHandle::MotherHandle(const Person& owner)
         : litesql::RelationHandle<Person>(owner) {
}
void Person::MotherHandle::link(const Person& o0) {
    PersonPersonRelationMother::link(owner->getDatabase(), *owner, o0);
}
void Person::MotherHandle::unlink(const Person& o0) {
    PersonPersonRelationMother::unlink(owner->getDatabase(), *owner, o0);
}
void Person::MotherHandle::del(const Expressions::PersonPersonRelationMother& srcExpr) {
    PersonPersonRelationMother::del(owner->getDatabase(), srcExpr && PersonPersonRelationMother::Person1 == owner->id);
}
litesql::DataSource<Person> Person::MotherHandle::get(const Expressions::Person& expr, const Expressions::PersonPersonRelationMother& srcExpr) {
    return PersonPersonRelationMother::getPerson2(owner->getDatabase(), expr, (PersonPersonRelationMother::Person1 == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::PersonPersonRelationMotherRow> Person::MotherHandle::getRows(const Expressions::PersonPersonRelationMother& srcExpr) {
    return PersonPersonRelationMother::getRows(owner->getDatabase(), srcExpr && (PersonPersonRelationMother::Person1 == owner->id));
}
Person::FatherHandle::FatherHandle(const Person& owner)
         : litesql::RelationHandle<Person>(owner) {
}
void Person::FatherHandle::link(const Person& o0) {
    PersonPersonRelationFather::link(owner->getDatabase(), *owner, o0);
}
void Person::FatherHandle::unlink(const Person& o0) {
    PersonPersonRelationFather::unlink(owner->getDatabase(), *owner, o0);
}
void Person::FatherHandle::del(const Expressions::PersonPersonRelationFather& srcExpr) {
    PersonPersonRelationFather::del(owner->getDatabase(), srcExpr && PersonPersonRelationFather::Person1 == owner->id);
}
litesql::DataSource<Person> Person::FatherHandle::get(const Expressions::Person& expr, const Expressions::PersonPersonRelationFather& srcExpr) {
    return PersonPersonRelationFather::getPerson2(owner->getDatabase(), expr, (PersonPersonRelationFather::Person1 == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::PersonPersonRelationFatherRow> Person::FatherHandle::getRows(const Expressions::PersonPersonRelationFather& srcExpr) {
    return PersonPersonRelationFather::getRows(owner->getDatabase(), srcExpr && (PersonPersonRelationFather::Person1 == owner->id));
}
Person::SiblingsHandle::SiblingsHandle(const Person& owner)
         : litesql::RelationHandle<Person>(owner) {
}
void Person::SiblingsHandle::link(const Person& o0) {
    PersonPersonRelationSiblings::link(owner->getDatabase(), *owner, o0);
}
void Person::SiblingsHandle::unlink(const Person& o0) {
    PersonPersonRelationSiblings::unlink(owner->getDatabase(), *owner, o0);
}
void Person::SiblingsHandle::del(const Expressions::PersonPersonRelationSiblings& srcExpr) {
    PersonPersonRelationSiblings::del(owner->getDatabase(), srcExpr && PersonPersonRelationSiblings::Person1 == owner->id);
}
litesql::DataSource<Person> Person::SiblingsHandle::get(const Expressions::Person& expr, const Expressions::PersonPersonRelationSiblings& srcExpr) {
    return PersonPersonRelationSiblings::getPerson2(owner->getDatabase(), expr, (PersonPersonRelationSiblings::Person1 == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::PersonPersonRelationSiblingsRow> Person::SiblingsHandle::getRows(const Expressions::PersonPersonRelationSiblings& srcExpr) {
    return PersonPersonRelationSiblings::getRows(owner->getDatabase(), srcExpr && (PersonPersonRelationSiblings::Person1 == owner->id));
}
Person::ChildrenHandle::ChildrenHandle(const Person& owner)
         : litesql::RelationHandle<Person>(owner) {
}
void Person::ChildrenHandle::link(const Person& o0) {
    PersonPersonRelationChildren::link(owner->getDatabase(), *owner, o0);
}
void Person::ChildrenHandle::unlink(const Person& o0) {
    PersonPersonRelationChildren::unlink(owner->getDatabase(), *owner, o0);
}
void Person::ChildrenHandle::del(const Expressions::PersonPersonRelationChildren& srcExpr) {
    PersonPersonRelationChildren::del(owner->getDatabase(), srcExpr && PersonPersonRelationChildren::Person1 == owner->id);
}
litesql::DataSource<Person> Person::ChildrenHandle::get(const Expressions::Person& expr, const Expressions::PersonPersonRelationChildren& srcExpr) {
    return PersonPersonRelationChildren::getPerson2(owner->getDatabase(), expr, (PersonPersonRelationChildren::Person1 == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::PersonPersonRelationChildrenRow> Person::ChildrenHandle::getRows(const Expressions::PersonPersonRelationChildren& srcExpr) {
    return PersonPersonRelationChildren::getRows(owner->getDatabase(), srcExpr && (PersonPersonRelationChildren::Person1 == owner->id));
}
Person::RolesHandle::RolesHandle(const Person& owner)
         : litesql::RelationHandle<Person>(owner) {
}
void Person::RolesHandle::link(const Role& o0) {
    RoleRelation::link(owner->getDatabase(), *owner, o0);
}
void Person::RolesHandle::unlink(const Role& o0) {
    RoleRelation::unlink(owner->getDatabase(), *owner, o0);
}
void Person::RolesHandle::del(const Expressions::RoleRelation& srcExpr) {
    RoleRelation::del(owner->getDatabase(), srcExpr && RoleRelation::Person == owner->id);
}
litesql::DataSource<Role> Person::RolesHandle::get(const Expressions::Role& expr, const Expressions::RoleRelation& srcExpr) {
    return RoleRelation::get<Role>(owner->getDatabase(), expr, (RoleRelation::Person == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::RoleRelationRow> Person::RolesHandle::getRows(const Expressions::RoleRelation& srcExpr) {
    return RoleRelation::getRows(owner->getDatabase(), srcExpr && (RoleRelation::Person == owner->id));
}
const std::string Person::type__("Person");
const std::string Person::table__("Person_");
const std::string Person::sequence__("Person_seq");
const Person::FieldType Person::Id("id_","INTEGER",table__);
const Person::FieldType Person::Type("type_","TEXT",table__);
const Person::FieldType Person::Name("name_","TEXT",table__);
const Person::FieldType Person::Age("age_","INTEGER",table__);
std::vector < std::pair< std::string, std::string > > Person::sex_values;
const Person::FieldType Person::Sex("sex_","INTEGER",table__,sex_values);
const Person::FieldType Person::DateOfBirth("dateOfBirth_","TIMESTAMP",table__);
void Person::initValues() {
    sex_values.clear();
    sex_values.push_back(make_pair<std::string, std::string>("Male","0"));
    sex_values.push_back(make_pair<std::string, std::string>("Female","1"));
}
void Person::defaults() {
    id = 0;
    age = 15;
    sex = 0;
}
Person::Person(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), name(Name), age(Age), sex(Sex), dateOfBirth(DateOfBirth) {
    defaults();
}
Person::Person(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), name(Name), age(Age), sex(Sex), dateOfBirth(DateOfBirth) {
    defaults();
    size_t size = (rec.size() > 6) ? 6 : rec.size();
    switch(size) {
    case 6: dateOfBirth = convert<const std::string&, litesql::DateTime>(rec[5]);
        dateOfBirth.setModified(false);
    case 5: sex = convert<const std::string&, int>(rec[4]);
        sex.setModified(false);
    case 4: age = convert<const std::string&, int>(rec[3]);
        age.setModified(false);
    case 3: name = convert<const std::string&, std::string>(rec[2]);
        name.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
Person::Person(const Person& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), name(obj.name), age(obj.age), sex(obj.sex), dateOfBirth(obj.dateOfBirth) {
}
const Person& Person::operator=(const Person& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        name = obj.name;
        age = obj.age;
        sex = obj.sex;
        dateOfBirth = obj.dateOfBirth;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
Person::MotherHandle Person::mother() const {
    return Person::MotherHandle(*this);
}
Person::FatherHandle Person::father() const {
    return Person::FatherHandle(*this);
}
Person::SiblingsHandle Person::siblings() const {
    return Person::SiblingsHandle(*this);
}
Person::ChildrenHandle Person::children() const {
    return Person::ChildrenHandle(*this);
}
Person::RolesHandle Person::roles() const {
    return Person::RolesHandle(*this);
}
std::string Person::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(name.name());
    values.push_back(name);
    name.setModified(false);
    fields.push_back(age.name());
    values.push_back(age);
    age.setModified(false);
    fields.push_back(sex.name());
    values.push_back(sex);
    sex.setModified(false);
    fields.push_back(dateOfBirth.name());
    values.push_back(dateOfBirth);
    dateOfBirth.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void Person::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Person::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, name);
    updateField(updates, table__, age);
    updateField(updates, table__, sex);
    updateField(updates, table__, dateOfBirth);
}
void Person::addIDUpdates(Updates& updates) {
}
void Person::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(Name);
    ftypes.push_back(Age);
    ftypes.push_back(Sex);
    ftypes.push_back(DateOfBirth);
}
void Person::delRecord() {
    deleteFromTable(table__, id);
}
void Person::delRelations() {
    PersonPersonRelationMother::del(*db, (PersonPersonRelationMother::Person1 == id) || (PersonPersonRelationMother::Person2 == id));
    PersonPersonRelationFather::del(*db, (PersonPersonRelationFather::Person1 == id) || (PersonPersonRelationFather::Person2 == id));
    PersonPersonRelationSiblings::del(*db, (PersonPersonRelationSiblings::Person1 == id) || (PersonPersonRelationSiblings::Person2 == id));
    PersonPersonRelationChildren::del(*db, (PersonPersonRelationChildren::Person1 == id) || (PersonPersonRelationChildren::Person2 == id));
    RoleRelation::del(*db, (RoleRelation::Person == id));
}
void Person::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect()) 
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void Person::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<Person> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool Person::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<Person> Person::upcast() {
    return auto_ptr<Person>(new Person(*this));
}
std::auto_ptr<Person> Person::upcastCopy() {
    Person* np = NULL;
    if (!np)
        np = new Person(*this);
    np->id = id;
    np->type = type;
    np->name = name;
    np->age = age;
    np->sex = sex;
    np->dateOfBirth = dateOfBirth;
    np->inDatabase = inDatabase;
    return auto_ptr<Person>(np);
}
std::ostream & operator<<(std::ostream& os, Person o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.name.name() << " = " << o.name << std::endl;
    os << o.age.name() << " = " << o.age << std::endl;
    os << o.sex.name() << " = " << o.sex << std::endl;
    os << o.dateOfBirth.name() << " = " << o.dateOfBirth << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
Role::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const Role::FieldType Role::Own::Id("id_","INTEGER","Role_");
Role::PersonHandle::PersonHandle(const Role& owner)
         : litesql::RelationHandle<Role>(owner) {
}
void Role::PersonHandle::link(const Person& o0) {
    RoleRelation::link(owner->getDatabase(), o0, *owner);
}
void Role::PersonHandle::unlink(const Person& o0) {
    RoleRelation::unlink(owner->getDatabase(), o0, *owner);
}
void Role::PersonHandle::del(const Expressions::RoleRelation& srcExpr) {
    RoleRelation::del(owner->getDatabase(), srcExpr && RoleRelation::Role == owner->id);
}
litesql::DataSource<Person> Role::PersonHandle::get(const Expressions::Person& expr, const Expressions::RoleRelation& srcExpr) {
    return RoleRelation::get<Person>(owner->getDatabase(), expr, (RoleRelation::Role == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::RoleRelationRow> Role::PersonHandle::getRows(const Expressions::RoleRelation& srcExpr) {
    return RoleRelation::getRows(owner->getDatabase(), srcExpr && (RoleRelation::Role == owner->id));
}
const std::string Role::type__("Role");
const std::string Role::table__("Role_");
const std::string Role::sequence__("Role_seq");
const Role::FieldType Role::Id("id_","INTEGER",table__);
const Role::FieldType Role::Type("type_","TEXT",table__);
void Role::defaults() {
    id = 0;
}
Role::Role(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type) {
    defaults();
}
Role::Role(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type) {
    defaults();
    size_t size = (rec.size() > 2) ? 2 : rec.size();
    switch(size) {
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
Role::Role(const Role& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type) {
}
const Role& Role::operator=(const Role& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
Role::PersonHandle Role::person() const {
    return Role::PersonHandle(*this);
}
std::string Role::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void Role::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Role::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
}
void Role::addIDUpdates(Updates& updates) {
}
void Role::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
}
void Role::delRecord() {
    deleteFromTable(table__, id);
}
void Role::delRelations() {
    RoleRelation::del(*db, (RoleRelation::Role == id));
}
void Role::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect()) 
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void Role::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<Role> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool Role::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<Role> Role::upcast() {
    if (type == Student::type__)
        return auto_ptr<Role>(new Student(select<Student>(*db, Id == id).one()));
    if (type == Employee::type__)
        return auto_ptr<Role>(new Employee(select<Employee>(*db, Id == id).one()));
    return auto_ptr<Role>(new Role(*this));
}
std::auto_ptr<Role> Role::upcastCopy() {
    Role* np = NULL;
    if (type == Student::type__)
        np = new Student(*db);
    if (type == Employee::type__)
        np = new Employee(*db);
    if (!np)
        np = new Role(*this);
    np->id = id;
    np->type = type;
    np->inDatabase = inDatabase;
    return auto_ptr<Role>(np);
}
std::ostream & operator<<(std::ostream& os, Role o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const Role::FieldType Student::Own::Id("id_","INTEGER","Student_");
Student::SchoolHandle::SchoolHandle(const Student& owner)
         : litesql::RelationHandle<Student>(owner) {
}
void Student::SchoolHandle::link(const School& o0) {
    SchoolStudentRelation::link(owner->getDatabase(), o0, *owner);
}
void Student::SchoolHandle::unlink(const School& o0) {
    SchoolStudentRelation::unlink(owner->getDatabase(), o0, *owner);
}
void Student::SchoolHandle::del(const Expressions::SchoolStudentRelation& srcExpr) {
    SchoolStudentRelation::del(owner->getDatabase(), srcExpr && SchoolStudentRelation::Student == owner->id);
}
litesql::DataSource<School> Student::SchoolHandle::get(const Expressions::School& expr, const Expressions::SchoolStudentRelation& srcExpr) {
    return SchoolStudentRelation::get<School>(owner->getDatabase(), expr, (SchoolStudentRelation::Student == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::SchoolStudentRelationRow> Student::SchoolHandle::getRows(const Expressions::SchoolStudentRelation& srcExpr) {
    return SchoolStudentRelation::getRows(owner->getDatabase(), srcExpr && (SchoolStudentRelation::Student == owner->id));
}
const std::string Student::type__("Student");
const std::string Student::table__("Student_");
Student::Student(const litesql::Database& db)
     : Role(db) {
}
Student::Student(const litesql::Database& db, const litesql::Record& rec)
     : Role(db, rec) {
}
Student::Student(const Student& obj)
     : Role(obj) {
}
const Student& Student::operator=(const Student& obj) {
    Role::operator=(obj);
    return *this;
}
Student::SchoolHandle Student::school() const {
    return Student::SchoolHandle(*this);
}
std::string Student::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back("id_");
    values.push_back(id);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return Role::insert(tables, fieldRecs, valueRecs);
}
void Student::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Student::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    Role::addUpdates(updates);
}
void Student::addIDUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
}
void Student::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    Role::getFieldTypes(ftypes);
}
void Student::delRecord() {
    deleteFromTable(table__, id);
    Role::delRecord();
}
void Student::delRelations() {
    SchoolStudentRelation::del(*db, (SchoolStudentRelation::Student == id));
}
void Student::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect()) 
            upcastCopy()->addIDUpdates(updates);
        else
            addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void Student::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<Student> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool Student::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<Student> Student::upcast() {
    return auto_ptr<Student>(new Student(*this));
}
std::auto_ptr<Student> Student::upcastCopy() {
    Student* np = NULL;
    if (!np)
        np = new Student(*this);
    np->inDatabase = inDatabase;
    return auto_ptr<Student>(np);
}
std::ostream & operator<<(std::ostream& os, Student o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const Role::FieldType Employee::Own::Id("id_","INTEGER","Employee_");
Employee::OfficeHandle::OfficeHandle(const Employee& owner)
         : litesql::RelationHandle<Employee>(owner) {
}
void Employee::OfficeHandle::link(const Office& o0) {
    EmployeeOfficeRelation::link(owner->getDatabase(), *owner, o0);
}
void Employee::OfficeHandle::unlink(const Office& o0) {
    EmployeeOfficeRelation::unlink(owner->getDatabase(), *owner, o0);
}
void Employee::OfficeHandle::del(const Expressions::EmployeeOfficeRelation& srcExpr) {
    EmployeeOfficeRelation::del(owner->getDatabase(), srcExpr && EmployeeOfficeRelation::Employee == owner->id);
}
litesql::DataSource<Office> Employee::OfficeHandle::get(const Expressions::Office& expr, const Expressions::EmployeeOfficeRelation& srcExpr) {
    return EmployeeOfficeRelation::get<Office>(owner->getDatabase(), expr, (EmployeeOfficeRelation::Employee == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::EmployeeOfficeRelationRow> Employee::OfficeHandle::getRows(const Expressions::EmployeeOfficeRelation& srcExpr) {
    return EmployeeOfficeRelation::getRows(owner->getDatabase(), srcExpr && (EmployeeOfficeRelation::Employee == owner->id));
}
const std::string Employee::type__("Employee");
const std::string Employee::table__("Employee_");
Employee::Employee(const litesql::Database& db)
     : Role(db) {
}
Employee::Employee(const litesql::Database& db, const litesql::Record& rec)
     : Role(db, rec) {
}
Employee::Employee(const Employee& obj)
     : Role(obj) {
}
const Employee& Employee::operator=(const Employee& obj) {
    Role::operator=(obj);
    return *this;
}
Employee::OfficeHandle Employee::office() const {
    return Employee::OfficeHandle(*this);
}
std::string Employee::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back("id_");
    values.push_back(id);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return Role::insert(tables, fieldRecs, valueRecs);
}
void Employee::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Employee::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    Role::addUpdates(updates);
}
void Employee::addIDUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
}
void Employee::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    Role::getFieldTypes(ftypes);
}
void Employee::delRecord() {
    deleteFromTable(table__, id);
    Role::delRecord();
}
void Employee::delRelations() {
    EmployeeOfficeRelation::del(*db, (EmployeeOfficeRelation::Employee == id));
}
void Employee::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect()) 
            upcastCopy()->addIDUpdates(updates);
        else
            addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void Employee::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<Employee> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool Employee::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<Employee> Employee::upcast() {
    return auto_ptr<Employee>(new Employee(*this));
}
std::auto_ptr<Employee> Employee::upcastCopy() {
    Employee* np = NULL;
    if (!np)
        np = new Employee(*this);
    np->inDatabase = inDatabase;
    return auto_ptr<Employee>(np);
}
std::ostream & operator<<(std::ostream& os, Employee o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
School::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const School::FieldType School::Own::Id("id_","INTEGER","School_");
School::StudentsHandle::StudentsHandle(const School& owner)
         : litesql::RelationHandle<School>(owner) {
}
void School::StudentsHandle::link(const Student& o0) {
    SchoolStudentRelation::link(owner->getDatabase(), *owner, o0);
}
void School::StudentsHandle::unlink(const Student& o0) {
    SchoolStudentRelation::unlink(owner->getDatabase(), *owner, o0);
}
void School::StudentsHandle::del(const Expressions::SchoolStudentRelation& srcExpr) {
    SchoolStudentRelation::del(owner->getDatabase(), srcExpr && SchoolStudentRelation::School == owner->id);
}
litesql::DataSource<Student> School::StudentsHandle::get(const Expressions::Role& expr, const Expressions::SchoolStudentRelation& srcExpr) {
    return SchoolStudentRelation::get<Student>(owner->getDatabase(), expr, (SchoolStudentRelation::School == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::SchoolStudentRelationRow> School::StudentsHandle::getRows(const Expressions::SchoolStudentRelation& srcExpr) {
    return SchoolStudentRelation::getRows(owner->getDatabase(), srcExpr && (SchoolStudentRelation::School == owner->id));
}
const std::string School::type__("School");
const std::string School::table__("School_");
const std::string School::sequence__("School_seq");
const School::FieldType School::Id("id_","INTEGER",table__);
const School::FieldType School::Type("type_","TEXT",table__);
const School::FieldType School::Name("name_","TEXT",table__);
void School::defaults() {
    id = 0;
}
School::School(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), name(Name) {
    defaults();
}
School::School(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), name(Name) {
    defaults();
    size_t size = (rec.size() > 3) ? 3 : rec.size();
    switch(size) {
    case 3: name = convert<const std::string&, std::string>(rec[2]);
        name.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
School::School(const School& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), name(obj.name) {
}
const School& School::operator=(const School& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        name = obj.name;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
School::StudentsHandle School::students() const {
    return School::StudentsHandle(*this);
}
std::string School::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(name.name());
    values.push_back(name);
    name.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void School::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void School::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, name);
}
void School::addIDUpdates(Updates& updates) {
}
void School::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(Name);
}
void School::delRecord() {
    deleteFromTable(table__, id);
}
void School::delRelations() {
    SchoolStudentRelation::del(*db, (SchoolStudentRelation::School == id));
}
void School::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect()) 
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void School::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<School> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool School::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<School> School::upcast() {
    return auto_ptr<School>(new School(*this));
}
std::auto_ptr<School> School::upcastCopy() {
    School* np = NULL;
    if (!np)
        np = new School(*this);
    np->id = id;
    np->type = type;
    np->name = name;
    np->inDatabase = inDatabase;
    return auto_ptr<School>(np);
}
std::ostream & operator<<(std::ostream& os, School o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.name.name() << " = " << o.name << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
Office::FieldType::FieldType(const std::string& name, const std::string& type, const std::string& table, const Values& values)
         : litesql::FieldType(name, type, table, values) {
    {}
}
const Office::FieldType Office::Own::Id("id_","INTEGER","Office_");
Office::EmployeesHandle::EmployeesHandle(const Office& owner)
         : litesql::RelationHandle<Office>(owner) {
}
void Office::EmployeesHandle::link(const Employee& o0) {
    EmployeeOfficeRelation::link(owner->getDatabase(), o0, *owner);
}
void Office::EmployeesHandle::unlink(const Employee& o0) {
    EmployeeOfficeRelation::unlink(owner->getDatabase(), o0, *owner);
}
void Office::EmployeesHandle::del(const Expressions::EmployeeOfficeRelation& srcExpr) {
    EmployeeOfficeRelation::del(owner->getDatabase(), srcExpr && EmployeeOfficeRelation::Office == owner->id);
}
litesql::DataSource<Employee> Office::EmployeesHandle::get(const Expressions::Role& expr, const Expressions::EmployeeOfficeRelation& srcExpr) {
    return EmployeeOfficeRelation::get<Employee>(owner->getDatabase(), expr, (EmployeeOfficeRelation::Office == owner->id) && srcExpr);
}
litesql::DataSource<RowTypes::EmployeeOfficeRelationRow> Office::EmployeesHandle::getRows(const Expressions::EmployeeOfficeRelation& srcExpr) {
    return EmployeeOfficeRelation::getRows(owner->getDatabase(), srcExpr && (EmployeeOfficeRelation::Office == owner->id));
}
const std::string Office::type__("Office");
const std::string Office::table__("Office_");
const std::string Office::sequence__("Office_seq");
const Office::FieldType Office::Id("id_","INTEGER",table__);
const Office::FieldType Office::Type("type_","TEXT",table__);
void Office::defaults() {
    id = 0;
}
Office::Office(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type) {
    defaults();
}
Office::Office(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type) {
    defaults();
    size_t size = (rec.size() > 2) ? 2 : rec.size();
    switch(size) {
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
Office::Office(const Office& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type) {
}
const Office& Office::operator=(const Office& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
Office::EmployeesHandle Office::employees() const {
    return Office::EmployeesHandle(*this);
}
std::string Office::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void Office::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void Office::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
}
void Office::addIDUpdates(Updates& updates) {
}
void Office::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
}
void Office::delRecord() {
    deleteFromTable(table__, id);
}
void Office::delRelations() {
    EmployeeOfficeRelation::del(*db, (EmployeeOfficeRelation::Office == id));
}
void Office::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect()) 
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void Office::del() {
    if (typeIsCorrect() == false) {
        std::auto_ptr<Office> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool Office::typeIsCorrect() {
    return type == type__;
}
std::auto_ptr<Office> Office::upcast() {
    return auto_ptr<Office>(new Office(*this));
}
std::auto_ptr<Office> Office::upcastCopy() {
    Office* np = NULL;
    if (!np)
        np = new Office(*this);
    np->id = id;
    np->type = type;
    np->inDatabase = inDatabase;
    return auto_ptr<Office>(np);
}
std::ostream & operator<<(std::ostream& os, Office o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
ExampleDatabase::ExampleDatabase(std::string backendType, std::string connInfo)
     : litesql::Database(backendType, connInfo) {
    initialize();
}
std::vector<litesql::Database::SchemaItem> ExampleDatabase::getSchema() const {
    vector<Database::SchemaItem> res;
    res.push_back(Database::SchemaItem("schema_","table","CREATE TABLE schema_ (name_ TEXT, type_ TEXT, sql_ TEXT);"));
    if (backend->supportsSequences()) {
        res.push_back(Database::SchemaItem("Person_seq","sequence","CREATE SEQUENCE Person_seq START 1 INCREMENT 1"));
        res.push_back(Database::SchemaItem("Role_seq","sequence","CREATE SEQUENCE Role_seq START 1 INCREMENT 1"));
        res.push_back(Database::SchemaItem("School_seq","sequence","CREATE SEQUENCE School_seq START 1 INCREMENT 1"));
        res.push_back(Database::SchemaItem("Office_seq","sequence","CREATE SEQUENCE Office_seq START 1 INCREMENT 1"));
    }
    res.push_back(Database::SchemaItem("Person_","table","CREATE TABLE Person_ (id_ " + backend->getRowIDType() + ",type_ TEXT,name_ TEXT,age_ INTEGER,sex_ INTEGER,dateOfBirth_ TIMESTAMP)"));
    res.push_back(Database::SchemaItem("Role_","table","CREATE TABLE Role_ (id_ " + backend->getRowIDType() + ",type_ TEXT)"));
    res.push_back(Database::SchemaItem("Student_","table","CREATE TABLE Student_ (id_ " + backend->getRowIDType() + ")"));
    res.push_back(Database::SchemaItem("Employee_","table","CREATE TABLE Employee_ (id_ " + backend->getRowIDType() + ")"));
    res.push_back(Database::SchemaItem("School_","table","CREATE TABLE School_ (id_ " + backend->getRowIDType() + ",type_ TEXT,name_ TEXT)"));
    res.push_back(Database::SchemaItem("Office_","table","CREATE TABLE Office_ (id_ " + backend->getRowIDType() + ",type_ TEXT)"));
    res.push_back(Database::SchemaItem("Person_Person_Mother","table","CREATE TABLE Person_Person_Mother (Person1 INTEGER UNIQUE,Person2 INTEGER)"));
    res.push_back(Database::SchemaItem("Person_Person_Father","table","CREATE TABLE Person_Person_Father (Person1 INTEGER UNIQUE,Person2 INTEGER)"));
    res.push_back(Database::SchemaItem("Person_Person_Siblings","table","CREATE TABLE Person_Person_Siblings (Person1 INTEGER,Person2 INTEGER)"));
    res.push_back(Database::SchemaItem("Person_Person_Children","table","CREATE TABLE Person_Person_Children (Person1 INTEGER,Person2 INTEGER)"));
    res.push_back(Database::SchemaItem("Person_Role_Roles","table","CREATE TABLE Person_Role_Roles (Person1 INTEGER,Role2 INTEGER UNIQUE)"));
    res.push_back(Database::SchemaItem("School_Student_","table","CREATE TABLE School_Student_ (School1 INTEGER,Student2 INTEGER UNIQUE)"));
    res.push_back(Database::SchemaItem("Employee_Office_","table","CREATE TABLE Employee_Office_ (Employee1 INTEGER,Office2 INTEGER)"));
    res.push_back(Database::SchemaItem("Person_Person_MotherPerson1idx","index","CREATE INDEX Person_Person_MotherPerson1idx ON Person_Person_Mother (Person1)"));
    res.push_back(Database::SchemaItem("Person_Person_MotherPerson2idx","index","CREATE INDEX Person_Person_MotherPerson2idx ON Person_Person_Mother (Person2)"));
    res.push_back(Database::SchemaItem("Person_Person_Mother_all_idx","index","CREATE INDEX Person_Person_Mother_all_idx ON Person_Person_Mother (Person1,Person2)"));
    res.push_back(Database::SchemaItem("Person_Person_FatherPerson1idx","index","CREATE INDEX Person_Person_FatherPerson1idx ON Person_Person_Father (Person1)"));
    res.push_back(Database::SchemaItem("Person_Person_FatherPerson2idx","index","CREATE INDEX Person_Person_FatherPerson2idx ON Person_Person_Father (Person2)"));
    res.push_back(Database::SchemaItem("Person_Person_Father_all_idx","index","CREATE INDEX Person_Person_Father_all_idx ON Person_Person_Father (Person1,Person2)"));
    res.push_back(Database::SchemaItem("_fc4501d1c1e9cc173fbe356a08a9d12f","index","CREATE INDEX _fc4501d1c1e9cc173fbe356a08a9d12f ON Person_Person_Siblings (Person1)"));
    res.push_back(Database::SchemaItem("_29908e51ecc673e39c38238d4abe5b3b","index","CREATE INDEX _29908e51ecc673e39c38238d4abe5b3b ON Person_Person_Siblings (Person2)"));
    res.push_back(Database::SchemaItem("Person_Person_Siblings_all_idx","index","CREATE INDEX Person_Person_Siblings_all_idx ON Person_Person_Siblings (Person1,Person2)"));
    res.push_back(Database::SchemaItem("_c77a0c252bbee950ec06bda52dd09648","index","CREATE INDEX _c77a0c252bbee950ec06bda52dd09648 ON Person_Person_Children (Person1)"));
    res.push_back(Database::SchemaItem("_64f9014350ce47b5d0f7606b127df7c3","index","CREATE INDEX _64f9014350ce47b5d0f7606b127df7c3 ON Person_Person_Children (Person2)"));
    res.push_back(Database::SchemaItem("Person_Person_Children_all_idx","index","CREATE INDEX Person_Person_Children_all_idx ON Person_Person_Children (Person1,Person2)"));
    res.push_back(Database::SchemaItem("Person_Role_RolesPerson1idx","index","CREATE INDEX Person_Role_RolesPerson1idx ON Person_Role_Roles (Person1)"));
    res.push_back(Database::SchemaItem("Person_Role_RolesRole2idx","index","CREATE INDEX Person_Role_RolesRole2idx ON Person_Role_Roles (Role2)"));
    res.push_back(Database::SchemaItem("Person_Role_Roles_all_idx","index","CREATE INDEX Person_Role_Roles_all_idx ON Person_Role_Roles (Person1,Role2)"));
    res.push_back(Database::SchemaItem("School_Student_School1idx","index","CREATE INDEX School_Student_School1idx ON School_Student_ (School1)"));
    res.push_back(Database::SchemaItem("School_Student_Student2idx","index","CREATE INDEX School_Student_Student2idx ON School_Student_ (Student2)"));
    res.push_back(Database::SchemaItem("School_Student__all_idx","index","CREATE INDEX School_Student__all_idx ON School_Student_ (School1,Student2)"));
    res.push_back(Database::SchemaItem("Employee_Office_Employee1idx","index","CREATE INDEX Employee_Office_Employee1idx ON Employee_Office_ (Employee1)"));
    res.push_back(Database::SchemaItem("Employee_Office_Office2idx","index","CREATE INDEX Employee_Office_Office2idx ON Employee_Office_ (Office2)"));
    res.push_back(Database::SchemaItem("Employee_Office__all_idx","index","CREATE INDEX Employee_Office__all_idx ON Employee_Office_ (Employee1,Office2)"));
    return res;
}
void ExampleDatabase::initialize() {
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
    Person::initValues();
}
}
