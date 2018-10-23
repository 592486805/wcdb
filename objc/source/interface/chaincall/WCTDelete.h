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

#import <WCDB/WCTUnsafeHandle.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Not Thread-safe
 */
@interface WCTDelete : WCTUnsafeHandle

- (instancetype)fromTable:(NSString *)tableName;

/**
 @brief WINQ interface for SQL.
 @param expr expr
 @return self
 */
- (instancetype)where:(const WCDB::Expression &)expr;

/**
 @brief WINQ interface for SQL.
 @param orders order list
 @return self
 */
- (instancetype)order:(const WCDB::OrderingTerms &)orders;

/**
 @brief WINQ interface for SQL.
 @param limit limit
 @return self
 */
- (instancetype)limit:(const WCDB::Expression &)limit;

/**
 @brief WINQ interface for SQL.
 @param offset offset
 @return self
 */
- (instancetype)offset:(const WCDB::Expression &)offset;

/**
 @brief Execute the delete SQL.
 @return YES if no error occurs.
 */
- (BOOL)execute;

- (WCDB::StatementDelete &)statement;

@end

NS_ASSUME_NONNULL_END