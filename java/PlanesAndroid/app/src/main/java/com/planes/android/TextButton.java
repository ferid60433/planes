package com.planes.android;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.Rect;
import android.support.v7.widget.AppCompatButton;
import android.util.AttributeSet;
import android.view.ViewGroup;

public class TextButton extends AppCompatButton {

    public TextButton(Context context) {
        super(context);
        init();
    }

    public TextButton(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    public TextButton(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        init();
    }

    public void init() {
        m_Paint = new Paint();
    }


    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        PlanesVerticalLayout.PlanesVerticalLayoutParams lp = (PlanesVerticalLayout.PlanesVerticalLayoutParams) getLayoutParams();
        m_Text = lp.getText();

        int measuredHeight = measureHeight(heightMeasureSpec);
        int measuredWidth = measureWidth(widthMeasureSpec);

        setMeasuredDimension(measuredWidth, measuredHeight);
    }

    private int measureHeight(int measureSpec) {
        int specMode = MeasureSpec.getMode(measureSpec);
        int specSize = MeasureSpec.getSize(measureSpec);

        int resultHeight = 10;

        m_Paint.setTextSize(20);
        Rect bounds = new Rect();
        m_Paint.getTextBounds(m_Text, 0, m_Text.length(), bounds);
        if (bounds.height() > resultHeight)
            resultHeight = bounds.height();

        if (specSize > resultHeight)
            resultHeight = specSize;

        return resultHeight;
    }

    private int measureWidth(int measureSpec) {
        int specMode = MeasureSpec.getMode(measureSpec);
        int specSize = MeasureSpec.getSize(measureSpec);

        int resultWidth = 10;

        m_Paint.setTextSize(20);
        Rect bounds = new Rect();
        m_Paint.getTextBounds(m_Text, 0, m_Text.length(), bounds);

        if (bounds.width() > resultWidth)
            resultWidth = bounds.width();

        if (specSize > resultWidth)
            resultWidth = specSize;

        return resultWidth;
    }


    @Override
    public void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        m_Paint.setColor(Color.BLUE);
        m_Paint.setTextSize(10);
        m_Paint.setTextAlign(Paint.Align.LEFT);
        int curTextSize = 0;

        int width = getWidth();
        int height = getHeight();

        int centerX = width / 2;
        int centerY = height / 2;

        int textWidth = 0;
        int textHeight = 0;

        int searchStep = 5;
        while (textWidth < width && textHeight < height) {
            curTextSize += searchStep;
            m_Paint.setTextSize(curTextSize);
            Rect bounds = new Rect();
            m_Paint.getTextBounds(m_Text, 0, m_Text.length(), bounds);
            textHeight = bounds.height();
            textWidth = bounds.width();
        }

        m_Paint.setTextSize(curTextSize - searchStep);
        Rect bounds = new Rect();
        m_Paint.getTextBounds(m_Text, 0, m_Text.length(), bounds);
        textHeight = bounds.height();
        textWidth = bounds.width();

        canvas.drawText(m_Text, centerX - textWidth / 2, centerY + textHeight / 2, m_Paint);
    }


    private Paint m_Paint;
    private String m_Text;
    private int m_MinWidth = 0;
    private int m_MinHeight = 0;
}
