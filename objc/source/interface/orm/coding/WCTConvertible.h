/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <WCDB/WCTCommon.h>

namespace WCDB {

//NSObject Subclass
template<typename T, typename Enable = void>
struct IsObjCType : std::false_type {
};

template<typename T>
struct IsObjCType<
T,
typename std::enable_if<std::is_convertible<NSObject *, T>::value && std::is_pointer<T>::value>::type> : std::true_type {
};

template<>
struct ColumnIsTextType<NSString *> : public std::true_type {
public:
    static ColumnTypeInfo<ColumnType::Text>::UnderlyingType
    asUnderlyingType(NSString *text);
};

template<>
struct ColumnIsFloatType<NSNumber *> : public std::true_type {
public:
    static ColumnTypeInfo<ColumnType::Float>::UnderlyingType
    asUnderlyingType(NSNumber *number);
};

#warning TODO
//    template<>
//    class LiteralValueConvertible<NSNumber *> : public std::true_type {
//    public:
//        static LiteralValue asLiteralValue(const NSNumber* number);
//    };

} //namespace WCDB