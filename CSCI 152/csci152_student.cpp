#include <iostream>
#include <stdexcept>
#include "csci152_student.h"



//public:

	/*
	 * Standard argument constructor -- you must copy the arrays!
	 *
	 * Do not worry about illegal inputs for this assignment - you do not need
	 * to throw an exception, or even try to handle them
	 */
	 
	csci152_student::csci152_student(
			std::string nm,
			unsigned int *asmts,
			unsigned int num_qs,
			unsigned int *quizzes,
			unsigned int final_exam
	){
		
			name = nm;
			num_of_quizzes = num_qs;
			assignment_scores = new unsigned int[4];
			quiz_scores = new unsigned int[num_of_quizzes];
			*quiz_scores = *quizzes;
			final_exam_score = final_exam;

			for(size_t i = 0; i< 4; i++){
				assignment_scores[i] = asmts[i];
			}
			for(size_t i = 0; i< num_of_quizzes; i++){
				quiz_scores[i] = quizzes[i];
			}
	}

	/*
	 * Copy constructor
	 */
	csci152_student::csci152_student(const csci152_student& other){
			name = other.name;
			assignment_scores = new unsigned int[4];
			num_of_quizzes = other.num_of_quizzes;
			quiz_scores = new unsigned int[num_of_quizzes];
			for(size_t i = 0; i< num_of_quizzes; i++){
				quiz_scores[i] = other.quiz_scores[i];
			}
			final_exam_score = other.final_exam_score;
			for(size_t i = 0; i< 4; i++){
				assignment_scores[i] = other.assignment_scores[i];
			}
	}

	/*
	 * Copy assignment - be careful to properly dispose of allocated memory for this
	 * before overwriting with values from other
	 */
	csci152_student& csci152_student::operator=(const csci152_student& other){
			delete[] assignment_scores;
			delete[] quiz_scores;
			name = other.name;
			assignment_scores = new unsigned int[4];
			num_of_quizzes = other.num_of_quizzes;
			final_exam_score = other.final_exam_score;
			quiz_scores = new unsigned int[num_of_quizzes];
			for(size_t i = 0; i< num_of_quizzes; i++){
				quiz_scores[i] = other.quiz_scores[i];
			}
			for(size_t i = 0; i< 4; i++){
				assignment_scores[i] = other.assignment_scores[i];
			}
			return *this;
	}


	/*
	 * Name getter
	 */
	std::string csci152_student::get_name() const{
	return name;
	}

	/*
	 * Calculates the average assignment score, between 0.0 and 100.0
	 */
	double csci152_student::calculate_assignment_perc() const{
		double a = 0;
		for(int i = 0; i< 4; i++){
			a = a + assignment_scores[i];
		}
		return a/4;
	}

	/*
	 * Calculates the total quiz percentage, where the lowest score is dropped from
	 * from the calculation.  Between 0.0 and 100.0
	 */
	double csci152_student::calculate_quiz_perc() const{
		double a = 0;
		size_t min = 20,b;

		for(int i = 0; i < num_of_quizzes; i++){
			if(min>quiz_scores[i]){
				min = quiz_scores[i];
				b = i;
			}
		}

		for(int i = 0; i< num_of_quizzes; i++){
			if(quiz_scores[i] == min){
				continue;
			}
			a = a + quiz_scores[i];
		}
		return 100.0*(a/(num_of_quizzes-1))/15;
	}


	/*
	 * Returns the value stored in final_exam_score
	 */
	unsigned int csci152_student::get_final_exam_perc() const{
	return final_exam_score;
	}

	/*
	 * Calculates the total course grade as a percent, using the weighting from
	 * the syllabus
	 */
	double csci152_student::calculate_course_perc() const{
		size_t a = calculate_assignment_perc()*0.2 + get_final_exam_perc()*0.4+calculate_quiz_perc()*0.4;
		}

	/*
	 * Destructor - don't forget you need to delete anything you explicitly allocated
	 */
	csci152_student::~csci152_student(){
		delete[] quiz_scores;
		delete[] assignment_scores;
	}
