#ifndef _RECIEVE_DATA_HPP_
#define _RECIEVE_DATA_HPP_

#include <memory>
#include <mutex>

#include "bounds_checked_array.hpp"
#include "digital_system.hpp"
#include "encoder_manager.hpp"
#include "fpga_encoder.hpp"
#include "joystick.hpp"
#include "match_info.hpp"
#include "mxp_data.hpp"
#include "robot_mode.hpp"

namespace hel{
    struct ReceiveData{
    private:
        std::string last_received_data;

        //BoundsCheckedArray<std::vector<int32_t>, hal::kNumAnalogInputs> analog_inputs; //TODO
        BoundsCheckedArray<bool, DigitalSystem::NUM_DIGITAL_HEADERS> digital_hdrs;
        BoundsCheckedArray<MXPData, DigitalSystem::NUM_DIGITAL_MXP_CHANNELS> digital_mxp;
        BoundsCheckedArray<Joystick, Joystick::MAX_JOYSTICK_COUNT>  joysticks;
        MatchInfo match_info;
        RobotMode robot_mode;
        BoundsCheckedArray<Maybe<EncoderManager>, FPGAEncoder::NUM_ENCODERS> encoder_managers;

        void deserializeDigitalHdrs(std::string&);
        void deserializeJoysticks(std::string&);
        void deserializeDigitalMXP(std::string&);
        void deserializeMatchInfo(std::string&);
        void deserializeRobotMode(std::string&);
        void deserializeEncoders(std::string&);

    public:
        void updateShallow()const;
        void updateDeep()const;

        std::string toString()const;

        void deserializeShallow(std::string);
        void deserializeDeep(std::string);

        ReceiveData();
    };

    class ReceiveDataManager{
    public:
        static std::pair<std::shared_ptr<ReceiveData>, std::unique_lock<std::recursive_mutex>> getInstance() {
            std::unique_lock<std::recursive_mutex> lock(receive_data_mutex);
            if(instance == nullptr){
                instance = std::make_shared<ReceiveData>();
            }
            return std::make_pair(instance, std::move(lock));
        }

    private:
        static std::shared_ptr<ReceiveData> instance;
        static std::recursive_mutex receive_data_mutex;
    };
}

#endif
