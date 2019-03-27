//
// Event_WIN32.h
//
// $Id: //poco/1.4/Foundation/include/Poco/Event_WIN32.h#1 $
//
// Library: Foundation
// Package: Threading
// Module:  Event
//
// Definition of the EventImpl class for WIN32.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_Event_WIN32_INCLUDED
#define Foundation_Event_WIN32_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Exception.h"
#include "Poco/UnWindows.h"


namespace Poco {


class Foundation_API EventImpl
{
public:
	enum EventTypeImpl
	{
		EVENT_MANUALRESET_IMPL,
		EVENT_AUTORESET_IMPL,
	};

protected:
	EventImpl(EventTypeImpl type);
	~EventImpl();
	void setImpl();
	void waitImpl();
	bool waitImpl(long milliseconds);
	void resetImpl();
	
private:
	HANDLE _event;
};


//
// inlines
//
inline void EventImpl::setImpl()
{
	if (!SetEvent(_event))
	{
		throw SystemException("cannot signal event");
	}
}


inline void EventImpl::resetImpl()
{
	if (!ResetEvent(_event))
	{
		throw SystemException("cannot reset event");
	}
}


} // namespace Poco


#endif // Foundation_Event_WIN32_INCLUDED