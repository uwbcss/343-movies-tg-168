#include "comedy.h"

ComedyFactory::ComedyFactory() { registerType("F", this); }

Movie *ComedyFactory::makeMovie() const { return new Comedy(); }

ComedyFactory anonymous_ComedyFactory;