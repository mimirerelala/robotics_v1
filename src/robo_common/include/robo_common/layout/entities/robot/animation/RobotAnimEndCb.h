#ifndef ROBO_COMMON_ROBOTANIMENDCB_H_
#define ROBO_COMMON_ROBOTANIMENDCB_H_

//C system headers

//C++ system headers
#include <cstdint>
#include <functional>

//Other libraries headers
#include "manager_utils/drawing/animation/AnimationEndCb.h"

//Own components headers
#include "robo_common/defines/RoboCommonDefines.h"
#include "robo_common/layout/field/FieldPos.h"

//Forward declarations

enum class RobotAnimEndCbReport {
  ENABLE, DISABLE
};

class RobotAnimEndCb final : public AnimationEndCb {
public:
  int32_t init(
      const std::function<void(Direction, const FieldPos&)>& onRobotsAnimEndCb);

  void setAnimEndData(Direction futureDir, const FieldPos& futurePos);

  int32_t onAnimationEnd() override;

  void setCbStatus(RobotAnimEndCbReport status);

private:
  std::function<void(Direction, const FieldPos&)> _onRobotsAnimEndCb;
  Direction _futureDir = Direction::UP;
  FieldPos _futurePos;
  RobotAnimEndCbReport _status = RobotAnimEndCbReport::ENABLE;
};

#endif /* ROBO_COMMON_ROBOTANIMENDCB_H_ */