#include <stdio.h>

#include "Processing.h"
#include "pages.h"

void PROCESSING_C(int choice, int choicetwo) {
	switch (choice) {
	case 1: {
		NEXTPAGE_STARTUP(); break;
	}
	case 2: {
		Task_SchedulerPAGE(); break;
	}
	default: {
		printf("Try to enter something else.");
		break;
	}
	}
}