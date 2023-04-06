//
//  PenDrawing.h
//  PenToolImplementation
//
//  Created by Gaurav Bhatia on 07/05/18.
//  Copyright © 2018 Hurix Systems. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef enum
{
    PEN_OBJECT_TYPE_DEFAULT = 3,
    PEN_OBJECT_TYPE_PROTRACTOR = 6
} PEN_OBJECT_TYPE;

@interface PenDrawingObject : NSObject

-(void)deSelect;
-(void)setDeleted;

@property (nonatomic, strong) UIBezierPath *bezierPath;
@property (nonatomic, assign) BOOL isSelected;

@property (nonatomic, strong) NSMutableArray *touchPointsArray;
@property (nonatomic, strong) UIColor *lineColor;
@property (nonatomic, strong) NSString *serverID;
@property (nonatomic, strong) NSString *penToolUUID;
@property (nonatomic, strong) NSDate *modifiedDate;
@property (nonatomic, assign) int pageID;
@property (nonatomic, strong) NSString *displayNum;
@property (nonatomic, assign) float lineWidth;
@property (nonatomic, assign) BOOL isSubmitted;
@property (nonatomic, assign) BOOL isDeleted;
@property (nonatomic, assign) BOOL isSynced;
@property (nonatomic, assign) PEN_OBJECT_TYPE penType;
@property (nonatomic, strong) NSDictionary *penToolData;
@property (nonatomic, assign) float protractorRadius;

@end
