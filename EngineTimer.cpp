#include "EngineTimer.h"

EngineTimer::EngineTimer()
{
	last = std::chrono::steady_clock::now();
}

float EngineTimer::Mark()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - old;
	return frameTime.count();
}

float EngineTimer::Peek() const
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}



