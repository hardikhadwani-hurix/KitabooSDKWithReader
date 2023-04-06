//
//  PenDrawingView.h
//  PenToolImplementation
//
//  Created by Gaurav Bhatia on 07/05/18.
//  Copyright © 2018 Hurix Systems. All rights reserved.
//
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "HSUIColor-Expanded.h"
#import "PenDrawingViewConstants.h"
#import "PenDrawingObject.h"


@protocol PenDrawingChangeDelegate <NSObject>
- (void)didCreatePenDrawing:(PenDrawingObject *)drawingObject;
- (void)didUpdatePenDrawing:(PenDrawingObject *)drawingObject;
- (void)didChangeReviewMode:(PenMode)penMode;
@end

@protocol PenDrawingSelectionChangeDelegate <NSObject>

- (void)didChangePenDrawingSelection:(PenDrawingObject *)drawingObject;
- (void)deleteSelectedDrawing;
- (void)enableUndoRedoButton:(BOOL)enable;
- (void)addUndoObjects:(PenDrawingObject *)pendrawingObject;
- (void)deleteUndoObjects:(PenDrawingObject *)pendrawingObject;
- (void)addRedoObjects:(PenDrawingObject *)pendrawingObject;

@end



@interface PenDrawingView : UIView

@property (nonatomic, weak) id <PenDrawingChangeDelegate> delegate;
@property (nonatomic, weak) id <PenDrawingSelectionChangeDelegate> selectionChangeDelegate;
@property (nonatomic, strong) UIImage *incrementalImage;
@property (nonatomic, assign) int pageID;
@property (nonatomic, strong) NSString *displayNum;

@property (atomic, strong) NSMutableArray *penDrawingsArray;
@property (nonatomic, assign) PenMode penMode;
@property (nonatomic, strong) UIColor *strokeColor;
@property (nonatomic, assign) float strokeWidth;
@property (nonatomic, assign) DRAWING_MODE drawingMode;
@property (nonatomic) CGAffineTransform invertScalingTransform;
@property (nonatomic) BOOL deleteOnSelectionEnabled;
@property (atomic, strong) NSMutableArray *protractorDrawingsArray;
@property (nonatomic) BOOL hasClassAssociation;

- (id)init;
- (void)clearContent;
- (void)loadAndDrawLastSavedData:(NSArray*)pathPointsArray;
- (void)handleTapGesture:(UIGestureRecognizer*)gesture;
- (void)setDeletedForSelectedDrawings;
- (void)setDeselectedForSelectedDrawings;
- (void)setDeletedForPenDrawing:(PenDrawingObject *)drawingObject;
- (void)undoDataWithPendrawingObject:(PenDrawingObject *)drawingObject;
- (void)redoDataWithPendrawingObject:(PenDrawingObject *)drawingObject;
- (void)clearAllPenDrawings;
- (void)loadAndDrawProtractorData:(NSArray *)pathPointsArray;

CGPoint CGPointMidPointOfPoints(CGPoint p1, CGPoint p2);
BOOL CGRectContainsLineWithPoints(CGRect rect, CGPoint startPoint, CGPoint endPoint);

@end
