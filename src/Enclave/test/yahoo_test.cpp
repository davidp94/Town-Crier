//
// Copyright (c) 2016-2018 by Cornell University.  All Rights Reserved.
//
// Permission to use the "TownCrier" software ("TownCrier"), officially
// docketed at the Center for Technology Licensing at Cornell University
// as D-7364, developed through research conducted at Cornell University,
// and its associated copyrights solely for educational, research and
// non-profit purposes without fee is hereby granted, provided that the
// user agrees as follows:
//
// The permission granted herein is solely for the purpose of compiling
// the TownCrier source code. No other rights to use TownCrier and its
// associated copyrights for any other purpose are granted herein,
// whether commercial or non-commercial.
//
// Those desiring to incorporate TownCrier software into commercial
// products or use TownCrier and its associated copyrights for commercial
// purposes must contact the Center for Technology Licensing at Cornell
// University at 395 Pine Tree Road, Suite 310, Ithaca, NY 14850; email:
// ctl-connect@cornell.edu; Tel: 607-254-4698; FAX: 607-254-5454 for a
// commercial license.
//
// IN NO EVENT SHALL CORNELL UNIVERSITY BE LIABLE TO ANY PARTY FOR
// DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES,
// INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF TOWNCRIER AND ITS
// ASSOCIATED COPYRIGHTS, EVEN IF CORNELL UNIVERSITY MAY HAVE BEEN
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// THE WORK PROVIDED HEREIN IS ON AN "AS IS" BASIS, AND CORNELL
// UNIVERSITY HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
// ENHANCEMENTS, OR MODIFICATIONS.  CORNELL UNIVERSITY MAKES NO
// REPRESENTATIONS AND EXTENDS NO WARRANTIES OF ANY KIND, EITHER IMPLIED
// OR EXPRESS, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, OR THAT THE USE
// OF TOWNCRIER AND ITS ASSOCIATED COPYRIGHTS WILL NOT INFRINGE ANY
// PATENT, TRADEMARK OR OTHER RIGHTS.
//
// TownCrier was developed with funding in part by the National Science
// Foundation (NSF grants CNS-1314857, CNS-1330599, CNS-1453634,
// CNS-1518765, CNS-1514261), a Packard Fellowship, a Sloan Fellowship,
// Google Faculty Research Awards, and a VMWare Research Award.
//

#include <stdio.h>
#include <stdlib.h>
#include <debug.h>
#include "tls_client.h"
#include "scrapers/scrapers.h"
#include "../log.h"


int yahoo_self_test(){

  	//printf("USAGE: get_flight_delay(YYYYMMDD, HHmm, flight#, return_variable)\n");
    //printf("\tdate/time in Zulu/UTC, flight in ICAO\n");
	
	//Null Checker
	double r = 0.0;

	if (yahoo_current(NULL, &r) != -1 || yahoo_current("GOOG", NULL) != -1 ||\
		yahoo_current(NULL, NULL) != -1){
		return -1;
	}

	//Test out regular performance
	
	if(yahoo_current("GOOG", &r) == -1){
		return -1;
	}
	LL_INFO("[Yahoo]Goog returns: %f", r);
	
	if (r == 0 || yahoo_current("AAPL", &r) == -1){
		return -1;
	}
	LL_INFO("[Yahoo]AAPL returns: %f", r);

	if (r == 0 || yahoo_current("ORCL", &r) == -1){
		return -1;
	}
	LL_INFO("[Yahoo]ORCL returns: %f", r);

	if (r == 0 || yahoo_current("YHOO", &r) == -1){
		return -1;
	}
	LL_INFO("[Yahoo]YHOO returns: %f", r);


	//Null check
	yahoo_current("vdbsd", &r);
	if (r != 0.0){
		return -1;
	}
	//stress test
	//for (int i = 0; i < 100; i++){
	//	if (yahoo_current("GOOG", &r) == -1){
	//		return -1;
	//	}
	//}

	return 0;
}
//1477276620,
//filed_departuretime":1477276620
//filed_departuretime":1477276620
