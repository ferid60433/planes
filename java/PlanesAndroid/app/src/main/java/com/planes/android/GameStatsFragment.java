package com.planes.android;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

public class GameStatsFragment extends Fragment {

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View window = null;
        window = inflater.inflate(R.layout.game_stats, container, false);
        createGUIMembers(window);
        return window;
    }

    public void createGUIMembers(View window) {
        m_HitsTextView = (TextView)window.findViewById(R.id.hits_count);
        m_DeadTextView = (TextView)window.findViewById(R.id.dead_count);
        m_MissesTextView = (TextView)window.findViewById(R.id.misses_count);
        m_MovesTextView = (TextView)window.findViewById(R.id.moves_count);

        m_HitsLabel = (TextView)window.findViewById(R.id.hits_label);
        m_DeadLabel = (TextView)window.findViewById(R.id.dead_label);
        m_MissesLabel = (TextView)window.findViewById(R.id.misses_label);
        m_MovesLabel = (TextView)window.findViewById(R.id.moves_label);
    }

    public void setLabelsText(boolean isPlayer) {
        if (isPlayer) {
            m_HitsLabel.setText(getResources().getString(R.string.player_hits));
            m_DeadLabel.setText(getResources().getString(R.string.player_dead));
            m_MissesLabel.setText(getResources().getString(R.string.player_misses));
            m_MovesLabel.setText(getResources().getString(R.string.player_moves));
        } else {
            m_HitsLabel.setText(getResources().getString(R.string.computer_hits));
            m_DeadLabel.setText(getResources().getString(R.string.computer_dead));
            m_MissesLabel.setText(getResources().getString(R.string.computer_misses));
            m_MovesLabel.setText(getResources().getString(R.string.computer_moves));
        }
    }

    public void updateStats(int misses, int hits, int dead, int moves, String missesText, String hitsText, String deadText, String movesText) {
        if (m_MissesTextView != null)
            m_MissesTextView.setText(Integer.toString(misses));
        if (m_HitsTextView != null)
            m_HitsTextView.setText(Integer.toString(hits));
        if (m_DeadTextView != null)
            m_DeadTextView.setText(Integer.toString(dead));
        if (m_MovesTextView != null)
            m_MovesTextView.setText(Integer.toString(moves));

        if (m_MissesLabel != null)
            m_MissesLabel.setText(missesText);
        if (m_HitsLabel != null)
            m_HitsLabel.setText(hitsText);
        if (m_DeadLabel != null)
            m_DeadLabel.setText(deadText);
        if (m_MovesLabel != null)
            m_MovesLabel.setText(movesText);
    }

    //dummy method overwritten in GameStatsWithToggleBoardButtonsFragmen
    public void setButtonsEnabled(boolean isComputer) {
    }

    protected TextView m_HitsTextView;
    protected TextView m_MissesTextView;
    protected TextView m_DeadTextView;
    protected TextView m_MovesTextView;
    protected TextView m_HitsLabel;
    protected TextView m_MissesLabel;
    protected TextView m_DeadLabel;
    protected TextView m_MovesLabel;
}