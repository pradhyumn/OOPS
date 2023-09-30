//HW2 by xxx
//SU Net ID: xx  SUID: xx
//Due: 11:59PM, Sept. 25 (Saturday)

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <tuple>
#include <vector>
#include <iomanip>
using namespace std;

class course {
public:
    string name;
    int section;
    int credits;
    string grade;
    course() {}
    course(string n, int s, int c, string g) { name = n; section = s; credits = c; grade = g; }

    float getGrade() const {
        map<string, float> gpa{ {"A", 4.0}, {"A-", 3.6666}, {"B+", 3.3333}, {"B", 3.0}, {"B-", 2.6666}, {"C+", 2.3333}, {"C", 2.0}, {"C-", 1.6666}, {"D", 1.0}, {"D-", 0.666}, {"F", 0.0} };

        float result;
        if (gpa.find(grade) == gpa.end()) {
            result = 0.0;
        }
        else {
            result = gpa[grade];
        }

        return result;
    }

    //You might need to implement some overloaded operators here.

    bool operator==(const course& c) const {
        return (c.name == name);
    }
    bool operator<=(const course& c) const {
        return (getGrade() <= c.getGrade());
    }
    bool operator>(const course& c) const {
        return (getGrade() > c.getGrade());
    }

};
//Implement the following functions.
//When adding a student, if the student is already in DB, then ignore the operation.
//When adding a course, if the course is already in DB, then ignore the operation.
//When dropping a course, if the course does not exist, then ignore the operation.
//When removing a student, if the student does not exist, then ignore the operation.
//All courses in a semester need to be sorted based on grade (from low to high).
//All semesters will be sorted (from low to high).
//When dropping or adding a course, overall GPA, semester GPA, overall credits and semester credits all need to be updated.

//Semeser numbers:  Spring 2019: 20191; Fall 2019: 20192, etc. 

void add_student(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int id);
void remove_student(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int id);
void add_course(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int semester, int id, course c); //20171 Spring semester of 2017; 20172: Fall semester of 2017
                                                                //All courses in the list should be sorted according to grade (increasing order)
void drop_course(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int semester, int id, course c);
void print_student_semester_courses(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int semester, int id);
void print_student_all_courses(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int id);

//Implement additional functions such that you can do
//cout << DB << endl;
ostream& operator<<(ostream& str, map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB) {
    for (auto studentIt = DB.begin(); studentIt != DB.end(); ++studentIt) {
        str << "Student ID: " << studentIt->first << endl;

        auto basicInfoPair = studentIt->second.first;
        list< pair<int, tuple<int, float, list<course* >* >* >* >* semesterList = studentIt->second.second;

        str << "Overall GPA : " << fixed << setprecision(2) << basicInfoPair->second << endl;
        str << "Overall Credits : " << basicInfoPair->first << endl;

        for (auto semesterIt = semesterList->begin(); semesterIt != semesterList->end(); ++semesterIt) {
            str << "Semester: " << (*semesterIt)->first << endl;
            auto semesterTuple = (*semesterIt)->second;
            str << "GPA : " << fixed << setprecision(2) << get<1>(*semesterTuple) << endl;
            str << "Credits : " << get<0>(*semesterTuple) << endl;

            auto courseList = get<2>(*semesterTuple);

            if (courseList->size() > 0) {
                for (auto courseIt = courseList->begin(); courseIt != courseList->end(); ++courseIt) {
                    str << "(" << (*courseIt)->name << " " << (*courseIt)->section << " " << (*courseIt)->credits << " " << (*courseIt)->grade << ") ";
                }
                str << endl;
            }
        }
    }

    return str;
}

//You might need to implement some overloaded operators in the course class.

int main() {

    map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>    DB;

    add_student(DB, 11111);
    course C1("CIS554", 1, 3, "A-"), C2("CSE674", 1, 3, "B+"), C3("MAT296", 8, 4, "A"), C4("WRT205", 5, 3, "A");

    add_course(DB, 20171, 11111, C1);
    add_course(DB, 20171, 11111, C4);
    add_course(DB, 20171, 11111, C3);
    add_course(DB, 20171, 11111, C2);
    print_student_semester_courses(DB, 20171, 11111);

    drop_course(DB, 20171, 11111, C1);
    print_student_semester_courses(DB, 20171, 11111); //sorted according to course name

    course C5("CIS351", 2, 3, "A-"), C6("PSY205", 5, 3, "B+"), C7("MAT331", 2, 3, "A"), C8("ECN203", 4, 3, "A");
    add_course(DB, 20172, 11111, C5);
    add_course(DB, 20172, 11111, C6);
    add_course(DB, 20172, 11111, C7);
    add_course(DB, 20172, 11111, C8);
    add_course(DB, 20172, 11111, C3);
    print_student_all_courses(DB, 11111);//ID GPA

    add_student(DB, 11112);
    add_course(DB, 20171, 11112, C2);
    add_course(DB, 20171, 11112, C5);
    add_course(DB, 20171, 11112, C7);
    add_course(DB, 20171, 11112, C4);
    print_student_semester_courses(DB, 20171, 11112);

    add_course(DB, 20172, 11112, C8);
    add_course(DB, 20172, 11112, C3);
    add_course(DB, 20172, 11112, C5);
    add_course(DB, 20172, 11112, C1);
    print_student_semester_courses(DB, 20172, 11112);

    print_student_all_courses(DB, 11112);

    cout << DB << endl;
    remove_student(DB, 11111);
    cout << DB << endl;
    remove_student(DB, 11112);
    return 0;
}

void add_student(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int id) {
    //Your code

    if (DB.find(id) != DB.end()) {
        return;
    }

    // create filler data structures
    list< pair<int, tuple<int, float, list<course* >* >* >* >* semesterList = new list< pair<int, tuple<int, float, list<course* >* >* >* >;

    // create student
    pair< pair<int, float>*, list< pair<int, tuple<int, float, list<course* >* >* >* >* > studentData{ new pair<int, float>(0, 0.0), semesterList };

    DB.emplace(id, studentData);
}

void remove_student(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int id) {
    //Your code

    auto it = DB.find(id);
    if (it == DB.end()) {
        return;
    }

    // delete all pointers
    auto basicInfoPair = it->second.first;
    list< pair<int, tuple<int, float, list<course* >* >* >* >* semesterList = it->second.second;

    for (auto semesterIt = semesterList->begin(); semesterIt != semesterList->end(); ++semesterIt) {
        tuple<int, float, list<course* >* >* semesterTuple = (*semesterIt)->second;
        list<course* >* courseList = get<2>(*semesterTuple);

        for (auto courseIt = courseList->begin(); courseIt != courseList->end(); ++courseIt) {
            delete (*courseIt);
        }
        courseList->clear();

        delete courseList;
        delete semesterTuple;
        delete (*semesterIt);
    }

    semesterList->clear();
    delete semesterList;
    delete basicInfoPair;

    DB.erase(id);
}


void add_course(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int semester, int id, course c) {
    //Your code

    // check if student exists
    auto studentIt = DB.find(id);
    if (studentIt == DB.end()) {
        return;
    }

    // check if semester exists
    auto basicInfoPair = studentIt->second.first;
    list< pair<int, tuple<int, float, list<course* >* >* >* >* semesterList = studentIt->second.second;
    auto semesterIt = semesterList->end();

    // check if this course exists in other semesters (if yes, dont add);
    for (auto it = semesterList->begin(); it != semesterList->end(); ++it) {
        tuple<int, float, list<course* >* >* semesterTuple = (*it)->second;
        list<course* >* courseList = get<2>(*semesterTuple);

        for (auto courseIt = courseList->begin(); courseIt != courseList->end(); ++courseIt) {
            if ((*courseIt)->name == c.name) {
                // same course exist, leave
                return;
            }
        }

        if ((*it)->first == semester) {
            // record semester match for adding course later
            semesterIt = it;
        }
    }

    // new course, add
    course* newCourse = new course(c.name, c.section, c.credits, c.grade);
    if (semesterIt != semesterList->end()) {
        // semester exists
        tuple<int, float, list<course* >* >* semesterTuple = (*semesterIt)->second;
        list<course* >* courseList = get<2>(*semesterTuple);
        bool insertedFlag = false;

        for (auto courseIt = courseList->begin(); courseIt != courseList->end(); ++courseIt) {
            if (c <= **courseIt) {
                // time to insert course
                insertedFlag = true;
                courseList->insert(courseIt, newCourse);
                break;
            }
        }

        if (!insertedFlag) {
            courseList->insert(courseList->end(), newCourse);
        }

        // change semester grade and credits
        get<1>(*semesterTuple) = (float)(((float)get<0>(*semesterTuple) * get<1>(*semesterTuple)) + ((float)c.getGrade() * c.credits)) / (float)(get<0>(*semesterTuple) + c.credits);
        get<0>(*semesterTuple) += c.credits;
    } else {
        // semester doesn't exist, create new semester in the right position;
        list<course* >* newCourseList = new list<course* >({ newCourse });
        auto newSemesterTuple = new tuple<int, float, list<course* >* >(c.credits, c.getGrade(), newCourseList);
        auto newSemesterPair = new pair<int, tuple<int, float, list<course* >* >* >(semester, newSemesterTuple);
        bool insertedFlag = false;

        for (semesterIt = semesterList->begin(); semesterIt != semesterList->end(); ++semesterIt) {
            if ((*semesterIt)->first > semester) {
                insertedFlag = true;
                semesterList->insert(semesterIt, newSemesterPair);
                break;
            }
        }

        if (!insertedFlag) {
            semesterList->insert(semesterList->end(), newSemesterPair);
        }
    }

    // change total credits and grade
    const int prevCredits = basicInfoPair->first;
    basicInfoPair->first += c.credits;
    basicInfoPair->second = ((basicInfoPair->second * (float)prevCredits) + ((float)c.credits * c.getGrade())) / (float)(basicInfoPair->first);
}

void drop_course(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int semester, int id, course c) {
    //Your code

    auto studentIt = DB.find(id);
    if (studentIt == DB.end()) {
        return;
    }

    // check if semester exsits
    auto basicInfoPair = studentIt->second.first;
    list< pair<int, tuple<int, float, list<course* >* >* >* >* semesterList = studentIt->second.second;
    for (auto semesterIt = semesterList->begin(); semesterIt != semesterList->end(); ++semesterIt) {

        if ((*semesterIt)->first == semester) {
            // semester exists
            tuple<int, float, list<course* >* >* semesterTuple = (*semesterIt)->second;
            list<course* >* courseList = get<2>(*semesterTuple);

            for (auto courseIt = courseList->begin(); courseIt != courseList->end(); ++courseIt) {
                if ((*courseIt)->name == c.name) {
                    // course exsits, drop course related actions here
                    delete (*courseIt);
                    courseList->erase(courseIt);

                    // reset semester score
                    const int prevSemesterCredits = get<0>(*semesterTuple);
                    get<0>(*semesterTuple) -= c.credits;
                    if (get<0>(*semesterTuple) != 0) {
                        get<1>(*semesterTuple) = (float)(((float)prevSemesterCredits * get<1>(*semesterTuple)) - ((float)c.getGrade() * c.credits)) / (float)(get<0>(*semesterTuple));
                    }
                    else {
                        get<1>(*semesterTuple) = 0.0;
                    }

                    // reset overall score
                    const int prevCredits = basicInfoPair->first;
                    basicInfoPair->first -= c.credits;
                    if ((basicInfoPair->first) != 0) {
                        basicInfoPair->second = ((basicInfoPair->second * (float)prevCredits) - ((float)c.credits * c.getGrade())) / (float)(basicInfoPair->first);
                    }
                    else {
                        basicInfoPair->second = 0.0;
                    }

                    break;
                }
            }

            break;
        }
    }
}

void print_student_semester_courses(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int semester, int id) {
    //Your code
    auto studentIt = DB.find(id);

    // check student
    if (studentIt == DB.end()) {
        return;
    }

    cout << "Student ID: " << id << endl;

    list< pair<int, tuple<int, float, list<course* >* >* >* >* semesterList = studentIt->second.second;

    for (auto semesterIt = semesterList->begin(); semesterIt != semesterList->end(); ++semesterIt) {
        // check semester
        if ((*semesterIt)->first == semester) {
            cout << "Semester: " << semester << endl;
            auto semesterTuple = (*semesterIt)->second;
            cout << "GPA : " << fixed << setprecision(2) << get<1>(*semesterTuple) << endl;
            cout << "Credits : " << get<0>(*semesterTuple) << endl;

            auto courseList = get<2>(*semesterTuple);

            for (auto courseIt = courseList->begin(); courseIt != courseList->end(); ++courseIt) {
                cout << "(" << (*courseIt)->name << " " << (*courseIt)->section << " " << (*courseIt)->credits << " " << (*courseIt)->grade << ") ";
            }
            cout << endl;
            cout << endl;
            break;
        }
    }
}
void print_student_all_courses(map<int, pair < pair<int, float>*, list<pair<int, tuple<int, float, list<course*  >*  >* >*>*>>& DB, int id) {
    //Your code
    auto studentIt = DB.find(id);

    if (studentIt == DB.end()) {
        return;
    }

    cout << "Student ID: " << id << endl;

    auto basicInfoPair = studentIt->second.first;
    list< pair<int, tuple<int, float, list<course* >* >* >* >* semesterList = studentIt->second.second;

    cout << "Overall GPA : " << fixed << setprecision(2) << basicInfoPair->second << endl;
    cout << "Overall Credits : " << basicInfoPair->first << endl;

    for (auto semesterIt = semesterList->begin(); semesterIt != semesterList->end(); ++semesterIt) {
        cout << "Semester: " << (*semesterIt)->first << endl;
        auto semesterTuple = (*semesterIt)->second;
        cout << "GPA : " << fixed << setprecision(2) << get<1>(*semesterTuple) << endl;
        cout << "Credits : " << get<0>(*semesterTuple) << endl;

        auto courseList = get<2>(*semesterTuple);

        if (courseList->size() > 0) {
            for (auto courseIt = courseList->begin(); courseIt != courseList->end(); ++courseIt) {
                cout << "(" << (*courseIt)->name << " " << (*courseIt)->section << " " << (*courseIt)->credits << " " << (*courseIt)->grade << ") ";
            }
            cout << endl;
        }
    }

    cout << endl;
}

// TODO: 
// 1. run tests on visual studio
// 2. check original test case output from visual studio