package com.planes.android;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;

import static java.lang.Math.min;

public class GridSquare extends View {
    public GridSquare(Context context) {
        super(context);
        init();
    }

    public GridSquare(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public GridSquare(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init();
    }

    public void setBackgroundColor(int r, int g, int b) {
        m_BackgroundColor = (255 & 0xff) << 24 | (r & 0xff) << 16 | (g & 0xff) << 8 | (b & 0xff);
    }

    public void setBackgroundColor(int color) {
        m_BackgroundColor = color;
    }

    public void setGuess(int guess_type) {
        m_GuessType = guess_type;
    }

    public void setRowCount(int row_count) {
        m_RowCount = row_count;
    }

    public void setColCount(int col_count) {
        m_ColCount = col_count;
    }

    public void setRow(int i) { m_Row = i; }
    public void setColumn(int j) { m_Col = j; }

    @Override
    protected void onDraw(Canvas canvas) {
        m_Paint.setStyle(Paint.Style.FILL);
        m_Paint.setColor(m_BackgroundColor);
        canvas.drawRect(getWidth() / 10, getHeight() / 10 , getWidth() * 9 / 10, getHeight() * 9 / 10, m_Paint);

        if (m_GuessType >= 0) {
            switch (m_GuessType) {
                case 0:
                    //draw red circle
                    m_Paint.setStyle(Paint.Style.FILL);
                    m_Paint.setColor(m_GuessColor);
                    canvas.drawOval(m_MissCircle, m_Paint);
                    break;
                case 1:
                    //draw triangle
                    m_Paint.setStyle(Paint.Style.FILL);
                    m_Paint.setColor(m_GuessColor);
                    canvas.drawPath(m_HitPath, m_Paint);
                    break;
                case 2:
                    //draw X
                    m_Paint.setStyle(Paint.Style.STROKE);
                    m_Paint.setColor(m_GuessColor);
                    canvas.drawLine(0, 0, getWidth(), getHeight(), m_Paint);
                    canvas.drawLine(0, getHeight(), getWidth(), 0, m_Paint);
                    break;
            }
        }
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        //int widthMode = MeasureSpec.getMode(widthMeasureSpec);
        int widthSize = MeasureSpec.getSize(widthMeasureSpec);
        //int heightMode = MeasureSpec.getMode(heightMeasureSpec);
        //int heightSize = MeasureSpec.getSize(heightMeasureSpec);
        int width = widthSize / m_ColCount;
        setMeasuredDimension(width, width);
        allocateMemory();
    }

    private void init() {
        m_Paint = new Paint();
    }

    //TODO is this correct
    private void allocateMemory() {
        m_MissCircle = new RectF(getWidth() / 4, getHeight() / 4, getWidth() * 3 / 2, getHeight() * 3/ 2); //TODO: to change
        m_HitPath = new Path();
        m_HitPath.moveTo(0, getHeight() / 2);
        m_HitPath.lineTo(getWidth() / 2, 0);
        m_HitPath.lineTo(getWidth(), getHeight() / 2);
        m_HitPath.lineTo(getWidth() / 2, getHeight());
        m_HitPath.lineTo(0, getHeight() / 2);
        m_HitPath.close();
    }

    public void setParent(TopPane_Vertical top) {
        m_Parent = top;
    }

    public boolean onTouchEvent(MotionEvent event) {
        m_Parent.changeSelection(m_Row, m_Col);
        return super.onTouchEvent(event);
    }


    private int m_BackgroundColor;
    private int m_GuessColor;
    private int m_GuessType = -1; //no guess
    private int m_RowCount = 10;
    private int m_ColCount = 10;
    private int m_Row = -1;
    private int m_Col = -1;
    private Paint m_Paint;
    private RectF m_MissCircle;
    private Path m_HitPath;

    private TopPane_Vertical m_Parent;
}