//
//  CXCalendarView.h
//  Calendar
//
//  Created by Vladimir Grichina on 13.07.11.
//  Copyright 2011 Componentix. All rights reserved.
//

#import "CXCalendarCellView.h"


@class CXCalendarView;


@protocol CXCalendarViewDelegate <NSObject>

@optional

- (void) calendarView: (CXCalendarView *) calendarView
        didSelectDate: (NSDate *) selectedDate;

@end


@interface CXCalendarView : UIView {
@protected
    NSCalendar *_calendar;

    NSDate *_selectedDate;

    NSDate *_displayedDate;

    UIView *_monthBar;
    UILabel *_monthLabel;
    UIButton *_monthBackButton;
    UIButton *_monthForwardButton;
    UIView *_weekdayBar;
    NSArray *_weekdayNameLabels;
    UIView *_gridView;
    NSArray *_dayCells;

    CGFloat _monthBarHeight;
    CGFloat _weekBarHeight;
}

@property(nonatomic) NSCalendar *calendar;

@property(nonatomic, unsafe_unretained) id<CXCalendarViewDelegate> delegate;

@property(nonatomic) NSDate *selectedDate;

@property(nonatomic) NSDate *displayedDate;
@property(nonatomic, readonly) NSUInteger displayedYear;
@property(nonatomic, readonly) NSUInteger displayedMonth;

- (void) monthForward;
- (void) monthBack;

- (void) reset;

// UI
@property(unsafe_unretained, readonly) UIView *monthBar;
@property(unsafe_unretained, readonly) UILabel *monthLabel;
@property(unsafe_unretained, readonly) UIButton *monthBackButton;
@property(unsafe_unretained, readonly) UIButton *monthForwardButton;
@property(unsafe_unretained, readonly) UIView *weekdayBar;
@property(unsafe_unretained, readonly) NSArray *weekdayNameLabels;
@property(unsafe_unretained, readonly) UIView *gridView;
@property(unsafe_unretained, readonly) NSArray *dayCells;

@property(assign) CGFloat monthBarHeight;
@property(assign) CGFloat weekBarHeight;

- (CXCalendarCellView *) cellForDate: (NSDate *) date;

@end