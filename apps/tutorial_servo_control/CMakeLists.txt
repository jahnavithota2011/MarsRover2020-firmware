add_executable(tutorial_servo_control.${TARGET}-board.elf)
target_sources(tutorial_servo_control.${TARGET}-board.elf PRIVATE src/main.cpp)
target_set_firmware_properties(tutorial_servo_control.${TARGET}-board.elf)
add_library(TutorialServo STATIC)
target_sources(TutorialServo PRIVATE src/TutorialServo.cpp)
target_link_libraries(tutorial_servo_contol.${TARGET}-board.elf
	PRIVATE
	TutorialServo
	)
target_include_directories(TutorialServo PUBLIC include)
target_set_mbed_dependency(TutorialServo)

