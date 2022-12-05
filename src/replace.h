#ifndef REPLACE_H
#define REPLACE_H

#include <string>

/// @brief Глобальная замена
/// @param where Где заменить
/// @param what Что заменить
/// @param withWhat Чем заменить
/// @return Строка с заменой
std::string replaceAll(const std::string &where, const std::string &what, const std::string &withWhat);

#endif // REPLACE_H