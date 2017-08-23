#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include <Engine/Math.h>

template <class T>
class Animation
{
	public:
	
	void setValue(const T& current, const T& target, double start, double delay) {_startValue = current; _targetValue = target; _start = start; _delay = delay; _currentValue = _startValue;}
	void setValue(const T& target, double start, double delay) {_startValue = _currentValue; _targetValue = target; _start = start; _delay = delay;}
	const T& getValue() const {return _currentValue;}
	
	float animate(double time)
	{
		double elapsed = time - _start;
		double t = clamp(elapsed / _delay, 0.0, 1.0);
		
		_currentValue = mix(_startValue, _targetValue, t);
	}
	
	T _startValue;
	T _targetValue;
	T _currentValue;
	
	double _start;
	double _delay;
};

#endif