#pragma once

#include "Signals.h"

class IMainDlgView
{
public:
	typedef sig::signal<void(double value)> CoeffChangeSignal;

	virtual void Show() = 0;

	typedef sig::signal<void()> InitSignal;


	virtual void SetNoSolution() = 0;
	virtual void SetInfiniteSolutions() = 0;
	virtual void SetSingleSolution(double solution) = 0;
	virtual void SetTwoRootsSolutuion(double root1, double root2) = 0;

	virtual void SetCoeffs(double a, double b, double c) = 0;

	// Signals
	virtual sig::connection DoOnInit(const InitSignal::slot_type & handler) = 0;
	virtual sig::connection DoOnCoeffAChange(const CoeffChangeSignal::slot_type & handler) = 0;
	virtual sig::connection DoOnCoeffBChange(const CoeffChangeSignal::slot_type & handler) = 0;
	virtual sig::connection DoOnCoeffCChange(const CoeffChangeSignal::slot_type & handler) = 0;

	virtual ~IMainDlgView() = default;
};