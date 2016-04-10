#include "BlockingJob.h"
#include "../Control.h"
#include "../SaveHandler.h"

BlockingJob::BlockingJob(Control* control, const char* name)
{
	XOJ_INIT_TYPE(BlockingJob);

	this->control = control;
	control->block(name);
}

BlockingJob::~BlockingJob()
{
	XOJ_CHECK_TYPE(BlockingJob);

	this->control = NULL;

	XOJ_RELEASE_TYPE(BlockingJob);
}

void BlockingJob::execute(bool noThreads)
{
	XOJ_CHECK_TYPE(BlockingJob);

	//printf("Running blockingJob.\n");
	this->run(false);

	g_idle_add((GSourceFunc) finished, this->control);
}

bool BlockingJob::finished(Control* control)
{
	//gdk_threads_leave();
	control->unblock();
	//gdk_threads_leave();

	// do not call again
	return false;
}

JobType BlockingJob::getType()
{
	return JOB_TYPE_BLOCKING;
}
